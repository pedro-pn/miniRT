#include "../test.h"

t_object	*_cone;
t_v3d		normal;
t_ray		r;
t_intxs		xs;
t_intx		*inter;

void test_setup(void) {
	xs.intersections = NULL;
	_cone = NULL;
}

void test_teardown(void) {
	/* Nothing */
	free(_cone);
	_cone = NULL;
}

void	intersecting_cone(t_object *cone, t_p3d point, t_v3d dir, double t0, double t1)
{
	r = ray(point, normalize(dir));
	xs = _cone->intersect(cone, r);
	
	mu_assert_int_eq(2, xs.count);
	
	inter = xs.intersections->content;
	mu_assert_double_eq(t0, inter->t);
	
	inter = xs.intersections->next->content;
	mu_assert_double_eq(t1, inter->t);
	ft_lstclear(&xs.intersections, free);
}

MU_TEST(intersect_cone_tst) {
	_cone = cone();
	intersecting_cone(_cone, point(0, 0, -5), vector(0, 0, 1), 5, 5);
	intersecting_cone(_cone, point(0, 0, -5), vector(1, 1, 1), 8.66025, 8.66025);
	intersecting_cone(_cone, point(1, 1, -5), vector(-0.5, -1, 1), 4.55006, 49.44994);
}

MU_TEST(parallel_halves_intersect) {
	_cone = cone();
	r = ray(point(0, 0, -1), normalize(vector(0, 1, 1)));
	xs = _cone->intersect(_cone, r);
	
	mu_assert_int_eq(1, xs.count);
	
	inter = xs.intersections->content;
	mu_assert_double_eq(0.35355, inter->t);
	ft_lstclear(&xs.intersections, free);
}

void	intersect_end_caps(t_object *cone, t_p3d point, t_v3d dir, int count) {
	cone->minimum = -0.5;
	cone->maximum = 0.5;
	cone->closed = true;
	r = ray(point, normalize(dir));
	xs = cone->intersect(cone, r);

	mu_assert_int_eq(count, xs.count);
	ft_lstclear(&xs.intersections, free);
}

MU_TEST(intersect_end_caps_tst) {
	_cone = cone();
	intersect_end_caps(_cone, point(0, 0, -5), vector(0, 1, 0), 0);
	intersect_end_caps(_cone, point(0, 0, -0.25), vector(0, 1, 1), 2);
	intersect_end_caps(_cone, point(0, 0, -0.25), vector(0, 1, 0), 4);
}

void	cone_normal(t_object *cone, t_p3d point, t_v3d expected) {
	normal = cone->normal(*cone, point);
	
	assert_tuple_eq(expected, normal);
}

MU_TEST(cone_normal_tst) {
	_cone = cone();
	
	cone_normal(_cone, point(0, 0, 0), vector(0, 0, 0));
	cone_normal(_cone, point(1, 1, 1), vector(1, -sqrt(2), 1));
	cone_normal(_cone, point(-1, -1, 0), vector(-1, 1, 0));
}

MU_TEST_SUITE(cone_suite) {
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(intersect_cone_tst);
	MU_RUN_TEST(parallel_halves_intersect);
	MU_RUN_TEST(intersect_end_caps_tst);
	MU_RUN_TEST(cone_normal_tst);
}

int main(int argc, char *argv[]) {
	MU_RUN_SUITE(cone_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}

