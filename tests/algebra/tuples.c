#include "../test.h"

t_t3d   result;
t_t3d   expected;
t_p3d	result_p;
t_p3d	expected_p;
t_v3d	expected_v;
t_v3d	result_v;

void test_setup(void) {
	
}

void test_teardown(void) {
	
}

MU_TEST(tuple_tst) {
	result = tuple_3d(4.3, -4.2, 3.1, 1.0);
    expected.x = 4.3;
    expected.y = -4.2;
    expected.z = 3.1;
    expected.w = 1.0;
    mu_assert_tuple_eq(expected, result);
}

MU_TEST(point_tst){
	result_p = point(4.3, -4.2, 3.1);
	expected_p.x = 4.3;
    expected_p.y = -4.2;
    expected_p.z = 3.1;
    expected_p.w = 1.0;
	mu_assert_tuple_eq(expected_p, result_p);
}

MU_TEST(vector_tst){
	result_v = vector(4.3, -4.2, 3.1);
	expected_v.x = 4.3;
    expected_v.y = -4.2;
    expected_v.z = 3.1;
    expected_v.w = 0.0;
	mu_assert_tuple_eq(expected_v, result_v);
}

MU_TEST(add_tuple_tst){
	result = add(tuple_3d(3, -2, 5, 1), tuple_3d(-2, 3, 1, 0));
	expected = tuple_3d(1, 1, 6, 1);
	mu_assert_tuple_eq(expected, result);
}

MU_TEST_SUITE(vector_suite) {
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(tuple_tst);
	MU_RUN_TEST(point_tst);
	MU_RUN_TEST(vector_tst);
	MU_RUN_TEST(add_tuple_tst);
}

int main(int argc, char *argv[]) {
	MU_RUN_SUITE(vector_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}