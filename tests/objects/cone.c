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
}

MU_TEST_SUITE(cone_suite) {
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(intersect_cone_tst);
	MU_RUN_TEST(parallel_halves_intersect);
}

int main(int argc, char *argv[]) {
	MU_RUN_SUITE(cone_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}

