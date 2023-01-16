#include "../test.h"

t_ray	_ray;
t_p3d	_position;

void test_setup(void) {
}

void test_teardown(void) {
	/* Nothing */
}

MU_TEST(ray_tst){
	_ray = ray(point(1, 2, 3), vector(4, 5, 6));
	
	mu_assert_tuple_eq(point(1, 2, 3), _ray.origin);
	mu_assert_tuple_eq(vector(4, 5, 6), _ray.direction);
}

MU_TEST(ray_t_tst){
	_ray = ray(point(2, 3, 4), vector(1, 0, 0));
	
	_position = position(0, _ray);
	mu_assert_tuple_eq(point(2, 3, 4), _position);

	_position = position(1, _ray);
	mu_assert_tuple_eq(point(3, 3, 4), _position);

	_position = position(-1, _ray);
	mu_assert_tuple_eq(point(1, 3, 4), _position);

	_position = position(2.5, _ray);
	mu_assert_tuple_eq(point(4.5, 3, 4), _position);
}

MU_TEST_SUITE(ray_suite) {
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(ray_tst);
	MU_RUN_TEST(ray_t_tst);
}

int main(int argc, char *argv[]) {
	MU_RUN_SUITE(ray_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
