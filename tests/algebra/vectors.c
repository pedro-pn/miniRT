#include "../test.h"

t_v3d	result;
t_v3d	expected;
double	res_mag;
double	result_dot;

void test_setup(void) {
	
}

void test_teardown(void) {
	
}

MU_TEST(magnitude_tst){
	res_mag = magnitude(vector(1, 0, 0));
	mu_assert_double_eq(1, res_mag);

	res_mag = magnitude(vector(0, 1, 0));
	mu_assert_double_eq(1, res_mag);

	res_mag = magnitude(vector(0, 0, 1));
	mu_assert_double_eq(1, res_mag);

	res_mag = magnitude(vector(1, 2, 3));
	mu_assert_double_eq(sqrt(14), res_mag);

	res_mag = magnitude(vector(-1, -2, -3));
	mu_assert_double_eq(sqrt(14), res_mag);
}

MU_TEST(normalization_tst){
	result = normalize(vector(4, 0, 0));
	expected = vector(1, 0, 0);
	assert_tuple_eq(expected, result);

	result = normalize(vector(1, 2, 3));
	expected = vector(1/sqrt(14), 2.0/sqrt(14), 3.0/sqrt(14));
	assert_tuple_eq(expected, result);

	res_mag = magnitude(expected);
	mu_assert_double_eq(1, res_mag);
}

MU_TEST(dot_tst)
{
	result_dot = dotp(vector(1, 2, 3), vector(2, 3, 4));
	mu_assert_double_eq(20, result_dot);
}

// 	Scenario : The cross product of two vectors
// Given a ← vector(1, 2, 3)
// And b ← vector(2, 3, 4)
// Then cross(a, b) = vector(-1, 2, -1)
// And cross(b, a) = vector(1, -2, 1)

MU_TEST(cross_tst)
{
	result = cross(vector(1, 2, 3), vector(2, 3, 4));
	expected = vector(-1, 2, -1);
	assert_tuple_eq(expected, result);

	result = cross(vector(2, 3, 4), vector(1, 2, 3));
	expected = vector(1, -2, 1);
	assert_tuple_eq(expected, result);
}

MU_TEST_SUITE(vector_suite) {
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(magnitude_tst);
	MU_RUN_TEST(normalization_tst);
	MU_RUN_TEST(dot_tst);
	MU_RUN_TEST(cross_tst);
}


int main(int argc, char *argv[]) {
	MU_RUN_SUITE(vector_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}