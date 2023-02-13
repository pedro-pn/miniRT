#include "../test.h"

t_ray	r;
t_intxs	xs;
t_object	*_cube;
t_object	*obj;
t_intx		*inter;

void test_setup(void) {
}

void test_teardown(void) {
	free(_cube);
}

void	cube_intersect(t_p3d origin, t_v3d direction, double t1, double t2, double count)
{
	_cube = cube();
	r = ray(origin, direction);
	xs = _cube->intersect(_cube, r);

	if (xs.count > 0)
	{
		inter = xs.intersections->content;
		mu_assert_double_eq(t1, inter->t);
	
		inter = xs.intersections->next->content;
		mu_assert_double_eq(t2, inter->t);
	}

	mu_assert_double_eq(count, xs.count);
}

MU_TEST(cube_tst) {
	cube_intersect(point(5, 0.5, 0), vector(-1, 0, 0), 4, 6, 2);
	cube_intersect(point(-5, 0.5, 0), vector(1, 0, 0), 4, 6, 2);
	cube_intersect(point(0.5, 5, 0), vector(0, -1, 0), 4, 6, 2);
	cube_intersect(point(0.5, -5, 0), vector(0, 1, 0), 4, 6, 2);
	cube_intersect(point(0.5, 0, 5), vector(0, 0, -1), 4, 6, 2);
	cube_intersect(point(0.5, 0, -5), vector(0, 0, 1), 4, 6, 2);
	cube_intersect(point(0, 0.5, 0), vector(0, 0, 1), -1, 1, 2);
}

MU_TEST(ray_misses_cube){
	cube_intersect(point(-2, 0, 0), vector(0.2673, 0.5345, 0.8018), 0, 0, 0);
	cube_intersect(point(0, -2, 0), vector(0.8018, 0.2673, 0.5345), 0 ,0, 0);
	cube_intersect(point(0, 0, -2), vector(0.5345, 0.8018, 0.2673), 0, 0, 0);
	cube_intersect(point(2, 0, 2), vector(0, 0, -1), 0, 0, 0);
	cube_intersect(point(0, 2, 2), vector(0, -1, 0), 0, 0, 0);
	cube_intersect(point(2, 2, 0), vector(-1, 0, 0), 0, 0, 0);
}

MU_TEST_SUITE(cube_suite) {
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(cube_tst);
	MU_RUN_TEST(ray_misses_cube);

}

int main(int argc, char *argv[]) {
	MU_RUN_SUITE(cube_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
