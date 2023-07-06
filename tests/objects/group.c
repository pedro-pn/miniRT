#include "../test.h"

t_group		*g;
t_group		*g2;
t_group		*g3;
t_group		*g4;
t_group		*g5;
t_group		*g6;
t_object	*s;
t_object	*s2;
t_object	*s3;
t_matrix	id;
t_object	*s;
t_object	*child;
t_group		*parent;
t_intx		*inter;
t_intxs		xs;
t_ray		r;
t_p3d		p;
t_v3d		n;

void test_setup(void) {
	g = group();
	xs.intersections = NULL;
}

void test_teardown(void) {
	/* Nothing */
	free_group(g);
	ft_lstclear(&xs.intersections, free);
}

MU_TEST(create_group_tst) {
	mx_identity(&id);

	mu_check(matrix_compare(id, g->transform) == true);
}

MU_TEST(parent_attribute_tst) {
	s = sphere();
	
	mu_check(s->parent == 0);
	free(s);
}

MU_TEST(add_child_to_group_tst) {
	s = sphere();
	add_child(g, s);
	child = g->group->content;
	parent = s->parent;
	
	mu_check(child == s);
	mu_check(parent == g);
}

MU_TEST(group_tree_free_tst) {
	g2 = group();
	g3 = group();
	g4 = group();
	g5 = group();
	g6 = group();

	add_child(g, sphere());
	add_child(g, g2);
	add_child(g2, g3);
	add_child(g3, sphere());
	add_child(g2, sphere());
	add_child(g2, g4);
	add_child(g4, sphere());
	add_child(g4, g5);
	add_child(g5, sphere());
	add_child(g5, g6);
	add_child(g6, sphere());
	add_child(g, sphere());
}

MU_TEST(ray_intersecting_empty_group_tst) {
	r = ray(point(0, 0, 0), vector(0, 0, 1));
	xs = g->intersect(g, r);
	
	mu_assert_int_eq(xs.count, 0);
	mu_check(xs.intersections == NULL);
}

MU_TEST(ray_intersecting_nonempty_group_tst) {
	s = sphere();
	s2 = sphere();
	translation(vector(0, 0, -3), &s2->transform);
	s3 = sphere();
	translation(vector(5, 0, 0), &s3->transform);
	add_child(g, s);
	add_child(g, s2);
	add_child(g, s3);
	r = ray(point(0, 0, -5), vector(0, 0, 1));
	xs = g->intersect(g, r);

	mu_assert_int_eq(4, xs.count);

	inter = xs.intersections->content;
	mu_check(inter->object == s2);

	inter = xs.intersections->next->content;
	mu_check(inter->object == s2);

	inter = xs.intersections->next->next->content;
	mu_check(inter->object == s);

	inter = xs.intersections->next->next->next->content;
	mu_check(inter->object == s);
}

MU_TEST(interscting_transformed_group_tst) {
	scaling(vector(2, 2, 2), &g->transform);
	s = sphere();
	translation(vector(5, 0, 0), &s->transform);
	add_child(g, s);
	r = ray(point(10, 0, -10), vector(0, 0, 1));
	xs = intersect_group(g, r);
	
	mu_assert_int_eq(2, xs.count);
}

MU_TEST(converting_point_from_world_to_object_space_tst) {
	rotation_y(MY_PI / 2, &g->transform);
	g2 = group();
	scaling(vector(2, 2, 2), &g2->transform);
	add_child(g, g2);
	s = sphere();
	translation(vector(5, 0, 0), &s->transform);
	add_child(g2, s);
	p = world_to_object(*s, point(-2, 0, -10));
	
	assert_tuple_eq(point(0, 0, -1), p);
}

MU_TEST(converting_normal_vector_from_object_to_world_space_tst) {
	rotation_y(MY_PI / 2, &g->transform);
	g2 = group();
	scaling(vector(1, 2, 3), &g2->transform);
	add_child(g, g2);
	s = sphere();
	translation(vector(5, 0, 0), &s->transform);
	add_child(g2, s);
	n = normal_to_world(*s, vector(sqrt(3) / 3, sqrt(3) / 3, sqrt(3) / 3));
	
	assert_tuple_eq(vector(0.2857, 0.4286, -0.8571), n);
}

MU_TEST(finding_normal_on_child_object_tst) {
	rotation_y(MY_PI / 2, &g->transform);
	g2 = group();
	scaling(vector(1, 2, 3), &g2->transform);
	add_child(g, g2);
	s = sphere();
	translation(vector(5, 0, 0), &s->transform);
	add_child(g2, s);
	n = normal_at(*s, point(1.7321, 1.1547, -5.5774), (t_intx){0});
	
	assert_tuple_eq(vector(0.2857, 0.4286, -0.8571), n);
}

MU_TEST_SUITE(group_suite) {
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(create_group_tst);
	MU_RUN_TEST(parent_attribute_tst);
	MU_RUN_TEST(add_child_to_group_tst);
	MU_RUN_TEST(group_tree_free_tst);
	MU_RUN_TEST(ray_intersecting_empty_group_tst);
	MU_RUN_TEST(ray_intersecting_nonempty_group_tst);
	MU_RUN_TEST(interscting_transformed_group_tst);
	MU_RUN_TEST(converting_point_from_world_to_object_space_tst);
	MU_RUN_TEST(converting_normal_vector_from_object_to_world_space_tst);
	MU_RUN_TEST(finding_normal_on_child_object_tst);
}

int main(int argc, char *argv[]) {
	MU_RUN_SUITE(group_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
