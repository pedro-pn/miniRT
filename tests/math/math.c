#include "../test.h"


t_quad	quad;
double	result;

void test_setup(void) {
}

void test_teardown(void) {
	/* Nothing */
}

MU_TEST(quadratic_tst) {
	quad = quadratic(1, 2, -3);

	mu_assert_double_eq(16, quad.det);
	mu_assert_double_eq(1, quad.root_a);
	mu_assert_double_eq(-3, quad.root_b);
}

MU_TEST(pow_tst){
	mu_assert_double_eq(32, dpow(2, 5));
	mu_assert_double_eq(1, dpow(50, 0));
	mu_assert_double_eq(10000, dpow(10, 4));
}

MU_TEST_SUITE(math_suite) {
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(quadratic_tst);
	MU_RUN_TEST(pow_tst);

}

int main(int argc, char *argv[]) {
	MU_RUN_SUITE(math_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}

