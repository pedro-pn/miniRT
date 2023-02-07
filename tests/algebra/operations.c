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

MU_TEST(add_tuple_tst){
	result = add(tuple_3d(3, -2, 5, 1), tuple_3d(-2, 3, 1, 0));
	expected = tuple_3d(1, 1, 6, 1);
	assert_tuple_eq(expected, result);
}

MU_TEST(sub_point_tst){
    result_v = sub(point(3, 2, 1), point(5, 6, 7));
    expected_v = vector(-2, -4, -6);
    assert_tuple_eq(expected, result);
}

MU_TEST(sub_vec_from_point_tst){
    result_p = sub(point(3, 2, 1), vector(5, 6, 7));
    expected_p = point(-2, -4, -6);
    assert_tuple_eq(expected, result);
}

MU_TEST(sub_vectors_tst){
    result_v = sub(vector(3, 2, 1), vector(5, 6, 7));
    expected_v = vector(-2, -4, -6);
    assert_tuple_eq(expected, result);
}

MU_TEST(negate_tuple){
    result = neg(tuple_3d(1, -2, 3, -4));
    expected = tuple_3d(-1, 2, -3, 4);
    assert_tuple_eq(expected, result);
}


MU_TEST(scalar_times_tst)
{
    result = scalar_times(3.5, tuple_3d(1, -2, 3, -4));
    expected = tuple_3d(3.5, -7, 10.5, -14);
    assert_tuple_eq(expected, result);

    result = scalar_times(0.5, tuple_3d(1, -2, 3, -4));
    expected = tuple_3d(0.5, -1, 1.5, -2);
    assert_tuple_eq(expected, result);
}

// Scenario : Dividing a tuple by a scalar
// Given a ← tuple(1, -2, 3, -4)
// Then a / 2 = tuple(0.5, -1, 1.5, -2)

MU_TEST(div_tst)
{
    result = scalar_div(2, tuple_3d(1, -2, 3, -4));
    expected = tuple_3d(0.5, -1, 1.5, -2);
    assert_tuple_eq(expected, result);
}

MU_TEST_SUITE(operation_suite) {
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(add_tuple_tst);
    MU_RUN_TEST(sub_point_tst);
    MU_RUN_TEST(sub_vec_from_point_tst);
    MU_RUN_TEST(sub_vectors_tst);
    MU_RUN_TEST(negate_tuple);
    MU_RUN_TEST(scalar_times_tst);
    MU_RUN_TEST(div_tst);
}


int main(int argc, char *argv[]) {
	MU_RUN_SUITE(operation_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}