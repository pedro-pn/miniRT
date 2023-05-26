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
t_object	*cy;
t_matrix	rot_x;
t_matrix	trans;
t_matrix	scal;
t_matrix	rot_y;
t_matrix	mx;
t_group		*g;
t_ray		r;
t_bucks		buckets;


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
	free_group(g);
	ft_lstclear(&buckets.left, free);
	ft_lstclear(&buckets.right, free);
}

MU_TEST_SUITE(bounding_box_volume_hierarchies) {
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(splitting_perfect_cube_tst);
	MU_RUN_TEST(splitting_x_wide_box_tst);
	MU_RUN_TEST(splitting_y_wide_box_tst);
	MU_RUN_TEST(splitting_z_wide_box_tst);
	MU_RUN_TEST(partitioning_group_child_tst);
}

int main(int argc, char *argv[]) {
	MU_RUN_SUITE(bounding_box_volume_hierarchies);
	MU_REPORT();
	return MU_EXIT_CODE;
}
