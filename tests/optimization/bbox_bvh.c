#include "../test.h"

t_box		box;
t_box		box_2;
t_box		b1;
t_sbox		boxes;
t_p3d		p1;
t_p3d		p2;
t_object	*obj;
t_object	*s;
t_object	*s2;
t_object	*s3;
t_object	*s4;
t_object	*cy;
t_matrix	rot_x;
t_matrix	trans;
t_matrix	scal;
t_matrix	rot_y;
t_matrix	mx;
t_group		*g;
t_group		*subgroup;
t_group		*sub1;
t_group		*sub2;
t_group		*subgroup;
t_group		*sub_subgroup;
t_ray		r;
t_bucks		buckets;
t_list		*list;


void test_setup(void) {
}

void test_teardown(void) {
	/* Nothing */
}

MU_TEST(splitting_perfect_cube_tst) {
	box = bounding_box(point(-1, -4, -5), point(9, 6, 5));
	boxes = split_bounds(box);

	assert_tuple_eq(point(-1, -4, -5), boxes.left.min);
	assert_tuple_eq(point(4, 6, 5), boxes.left.max);
	assert_tuple_eq(point(4, -4, -5), boxes.right.min);
	assert_tuple_eq(point(9, 6, 5), boxes.right.max);
}

MU_TEST(splitting_x_wide_box_tst) {
	box = bounding_box(point(-1, -2, -3), point(9, 5.5, 3));
	boxes = split_bounds(box);

	assert_tuple_eq(point(-1, -2, -3), boxes.left.min);
	assert_tuple_eq(point(4, 5.5, 3), boxes.left.max);
	assert_tuple_eq(point(4, -2, -3), boxes.right.min);
	assert_tuple_eq(point(9, 5.5, 3), boxes.right.max);
}

MU_TEST(splitting_y_wide_box_tst) {
	box = bounding_box(point(-1, -2, -3), point(5, 8, 3));
	boxes = split_bounds(box);

	assert_tuple_eq(point(-1, -2, -3), boxes.left.min);
	assert_tuple_eq(point(5, 3, 3), boxes.left.max);
	assert_tuple_eq(point(-1, 3, -3), boxes.right.min);
	assert_tuple_eq(point(5, 8, 3), boxes.right.max);
}

MU_TEST(splitting_z_wide_box_tst) {
	box = bounding_box(point(-1, -2, -3), point(5, 3, 7));
	boxes = split_bounds(box);

	assert_tuple_eq(point(-1, -2, -3), boxes.left.min);
	assert_tuple_eq(point(5, 3, 2), boxes.left.max);
	assert_tuple_eq(point(-1, -2, 2), boxes.right.min);
	assert_tuple_eq(point(5, 3, 7), boxes.right.max);
}

MU_TEST(partitioning_group_child_tst) {
	s = sphere();
	translation(vector(-2, 0, 0), &s->transform);

	s2 = sphere();
	translation(vector(2, 0, 0), &s2->transform);
	
	s3 = sphere();
	g = group();
	add_child(g, s);
	add_child(g, s2);
	add_child(g, s3);
	buckets = partition_children(g);

	mu_check(g->group->content == s3);
	mu_check(buckets.left->content == s);
	mu_check(buckets.right->content == s2);
	mu_check(ft_lstsize(g->group) == 1);

	free_group(g);
	ft_lstclear(&buckets.left, free);
	ft_lstclear(&buckets.right, free);
}

MU_TEST(creating_sub_group_from_bucket_tst) {
	s = sphere();
	s2 = sphere();
	g = group();
	list = ft_lstnew(s);
	ft_lstadd_back(&list, ft_lstnew(s2));
	make_subgroup(g, list);
	
	subgroup = g->group->content;
	obj = subgroup->group->content;
	mu_check(obj == s);

	obj = subgroup->group->next->content;
	mu_check(obj == s2);
	
	free_group(g);
}

MU_TEST(subdividing_primitive_does_nothing_tst) {
	s = sphere();
	divide(s, 1);

	mu_check(s == s);
	free(s);
}

MU_TEST(subdividing_group_partitions_tst) {
	s = sphere();
	translation(vector(-2, -2, 0), &s->transform);

	s2 = sphere();
	translation(vector(-2, 2, 0), &s2->transform);

	s3 = sphere();
	scaling(vector(4, 4, 4), &s3->transform);
	
	g = group();
	add_child(g, s);
	add_child(g, s2);
	add_child(g, s3);
	divide (g, 1);

	obj = g->group->content;
	mu_check(obj == s3);

	subgroup = g->group->next->content;
	mu_check(subgroup->type == GROUP);
	sub_subgroup = subgroup->group->content;
	obj = sub_subgroup->group->content;
	mu_check(obj == s);
	mu_check(sub_subgroup->type == GROUP);

	sub_subgroup = subgroup->group->next->content;
	obj = sub_subgroup->group->content;
	mu_check(obj == s2);
	mu_check(sub_subgroup->type == GROUP);
	free_group(g);
}

MU_TEST(subdividing_group_with_too_few_children_tst) {
	s = sphere();
	translation(vector(-2, 0, 0), &s->transform);

	s2 = sphere();
	translation(vector(2, 1, 0), &s2->transform);

	s3 = sphere();
	translation(vector(2, -1, 0), &s3->transform);

	subgroup = group();
	add_child(subgroup, s);
	add_child(subgroup, s2);
	add_child(subgroup, s3);
	g = group();
	add_child(g, subgroup);
	s4 = sphere();
	add_child(g, s4);
	divide(g, 3);

	sub1 = g->group->content;
	mu_check(sub1 == subgroup);
	mu_assert_int_eq(2, ft_lstsize(sub1->group));
	obj = g->group->next->content;
	mu_check(obj == s4);


	sub_subgroup = sub1->group->content;
	obj = sub_subgroup->group->content;
	mu_check(obj == s);

	sub_subgroup = sub1->group->next->content;
	obj = sub_subgroup->group->content;
	mu_check(obj == s2);

	obj = sub_subgroup->group->next->content;
	mu_check(obj == s3);
	free_group(g);
}

MU_TEST_SUITE(bounding_box_volume_hierarchies) {
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(splitting_perfect_cube_tst);
	MU_RUN_TEST(splitting_x_wide_box_tst);
	MU_RUN_TEST(splitting_y_wide_box_tst);
	MU_RUN_TEST(splitting_z_wide_box_tst);
	MU_RUN_TEST(partitioning_group_child_tst);
	MU_RUN_TEST(creating_sub_group_from_bucket_tst);
	MU_RUN_TEST(subdividing_primitive_does_nothing_tst);
	MU_RUN_TEST(subdividing_group_partitions_tst);
	MU_RUN_TEST(subdividing_group_with_too_few_children_tst);
}

int main(int argc, char *argv[]) {
	MU_RUN_SUITE(bounding_box_volume_hierarchies);
	MU_REPORT();
	return MU_EXIT_CODE;
}
