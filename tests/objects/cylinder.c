#include "../test.h"

t_object	*_cylinder;
t_v3d		normal;
t_ray		r;
t_intxs		xs;
t_intx		*inter;

void test_setup(void) {
	xs.intersections = NULL;
}

void test_teardown(void) {
	/* Nothing */
	free(_cylinder);
	ft_lstclear(&xs.intersections, free);
}

void	test_cylinder_intersection(t_object *obj, t_ray ray, int expected) {
	ray.direction = normalize(ray.direction);
	xs = intersect_cylinder(obj, ray);

	mu_assert_int_eq(expected, xs.count);
	
}

MU_TEST(ray_misses_cylinder_tst) {
	_cylinder = cylinder();
	r = ray(point(1, 0, 0), vector(0, 1, 0));
	test_cylinder_intersection(_cylinder, r, 0);

	r = ray(point(0, 0, 0), vector(0, 1, 0));
	test_cylinder_intersection(_cylinder, r, 0);
	
	r = ray(point(0, 0, -5), vector(1, 1, 1));
	test_cylinder_intersection(_cylinder, r, 0);
}

MU_TEST_SUITE(cylinder_suite) {
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(ray_misses_cylinder_tst);

}

int main(int argc, char *argv[]) {
	MU_RUN_SUITE(cylinder_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}

