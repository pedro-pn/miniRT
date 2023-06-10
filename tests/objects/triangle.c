#include "../test.h"

t_object	*t;
t_object	*obj;
t_p3d		p1;
t_p3d		p2;
t_p3d		p3;
t_v3d		v;
t_v3d		n1;
t_v3d		n2;
t_v3d		n3;
t_ray		r;
t_intxs		xs;
t_intx		*inter;


void test_setup(void) {
}

void test_teardown(void) {
	/* Nothing */
}

MU_TEST(creating_triangle_tst) {
	p1 = point(0, 1, 0);
	p2 = point(-1, 0, 0);
	p3 = point(1, 0, 0);
	t = triangle(p1, p2, p3);

	assert_tuple_eq(p1, t->p1);
	assert_tuple_eq(p2, t->p2);
	assert_tuple_eq(p3, t->p3);
	assert_tuple_eq(vector(-1, -1, 0), t->e1);
	assert_tuple_eq(vector(1, -1, 0), t->e2);
	assert_tuple_eq(vector(0, 0, -1), t->normalv);
	free(t);
}

MU_TEST(finding_normal_on_a_triangle_tst) {
	t = triangle(point(0, 1, 0), point(-1, 0, 0), point(1, 0, 0));
	n1 = t->normal(*t, point(0, 0.5, 0));
	n2 = t->normal(*t, point(-0.5, 0.75, 0));
	n3 = t->normal(*t, point(0.5, 0.25, 0));

	assert_tuple_eq(t->normalv, n1);
	assert_tuple_eq(t->normalv, n2);
	assert_tuple_eq(t->normalv, n3);
	free(t);
}

MU_TEST(intersecting_a_ray_parallel_to_the_triangle_tst) {
	t = triangle(point(0, 1, 0), point(-1, 0, 0), point(1, 0, 0));
	r = ray(point(0, -1, -2), vector(0, 1, 0));
	
	xs = t->intersect(t, r);

	mu_assert_int_eq(0, xs.count);
	mu_check(xs.intersections == NULL);
	free(t);
}

MU_TEST(ray_misses_the_p1_p3_edge_tst) {
	t = triangle(point(0, 1, 0), point(-1, 0, 0), point(1, 0, 0));
	r = ray(point(1, 1, -2), vector(0, 0, 1));
	
	xs = t->intersect(t, r);

	mu_assert_int_eq(0, xs.count);
	mu_check(xs.intersections == NULL);
	free(t);
}

MU_TEST(ray_misses_the_p1_p2_edge_tst) {
	t = triangle(point(0, 1, 0), point(-1, 0, 0), point(1, 0, 0));
	r = ray(point(-1, 1, -2), vector(0, 0, 1));
	
	xs = t->intersect(t, r);

	mu_assert_int_eq(0, xs.count);
	mu_check(xs.intersections == NULL);
	free(t);
}

MU_TEST(ray_misses_the_p2_p3_edge_tst) {
	t = triangle(point(0, 1, 0), point(-1, 0, 0), point(1, 0, 0));
	r = ray(point(0, -1, -2), vector(0, 0, 1));
	
	xs = t->intersect(t, r);

	mu_assert_int_eq(0, xs.count);
	mu_check(xs.intersections == NULL);
	free(t);
}

MU_TEST(ray_strikes_a_triangle_tst) {
	t = triangle(point(0, 1, 0), point(-1, 0, 0), point(1, 0, 0));
	r = ray(point(0, 0.5, -2), vector(0, 0, 1));
	
	xs = t->intersect(t, r);

	mu_assert_int_eq(1, xs.count);
	inter = xs.intersections->content;
	mu_assert_double_eq(2, inter->t);
	mu_check(inter->object == t);
	free(t);
}

MU_TEST_SUITE(triangle_suite) {
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(creating_triangle_tst);
	MU_RUN_TEST(finding_normal_on_a_triangle_tst);
	MU_RUN_TEST(intersecting_a_ray_parallel_to_the_triangle_tst);
	MU_RUN_TEST(ray_misses_the_p1_p3_edge_tst);
	MU_RUN_TEST(ray_misses_the_p1_p2_edge_tst);
	MU_RUN_TEST(ray_misses_the_p2_p3_edge_tst);
	MU_RUN_TEST(ray_strikes_a_triangle_tst);
}

int main(int argc, char *argv[]) {
	MU_RUN_SUITE(triangle_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
