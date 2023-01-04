#include "../test.h"

t_t3d   result;
t_t3d   expected;

void test_setup(void) {
	
}

void test_teardown(void) {
	
}
// Scenario : A tuple with w=1.0 is a point
// Given a ← tuple(4.3, -4.2, 3.1, 1.0)
// Then a.x = 4.3
// And a.y = -4.2
// And a.z = 3.1
// And a.w = 1.0
// And a is a point
// And a is not a vector
MU_TEST(tuple_tst) {
	result = tuple_3d(4.3, -4.2, 3.1, 1.0);
    expected.x = 4.3;
    expected.y = -4.2;
    expected.z = 3.1;
    expected.w = 1.0;
    mu_assert_tuple_eq(expected, result);
}

// Scenario : A tuple with w=0 is a vector
// Given a ← tuple(4.3, -4.2, 3.1, 0.0)
// Then a.x = 4.3
// And a.y = -4.2
// And a.z = 3.1
// And a.w = 0.0
// And a is not a point
// MU_TEST(test_check) {
// 	;
// }


MU_TEST_SUITE(vector_suite) {
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(tuple_tst);
}

int main(int argc, char *argv[]) {
	MU_RUN_SUITE(vector_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}