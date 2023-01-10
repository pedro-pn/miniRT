#include "../test.h"
#include <stdio.h>

t_c3d	result;
t_c3d	expected;


void test_setup(void) {
}

void test_teardown(void) {
	/* Nothing */
}


MU_TEST(tcolor_tst) {
	result = tcolor(-0.5, 0.4, 1.7);
	expected.x = -0.5;
	expected.y = 0.4;
	expected.z = 1.7;
	expected.w = 0;
	mu_assert_tuple_eq(expected, result);
}

MU_TEST(add_color_tst){
	result = add(tcolor(0.9, 0.6, 0.75), tcolor(0.7, 0.1, 0.25));
	expected = tcolor(1.6, 0.7, 1.0);
	mu_assert_tuple_eq(expected, result);
}

MU_TEST(sub_color_tst){
	result = sub(tcolor(0.9, 0.6, 0.75), tcolor(0.7, 0.1, 0.25));
	expected = tcolor(0.2, 0.5, 0.5);
	mu_assert_tuple_eq(expected, result);
}

MU_TEST(multplying_color_tst){
	result = scalar_times(2, tcolor(0.2, 0.3, 0.4));
	expected = tcolor(0.4, 0.6, 0.8);
	mu_assert_tuple_eq(expected, result);
}

MU_TEST(haddamard_product_tst){
	result = haddamard(tcolor(1, 0.2, 0.4), tcolor(0.9, 1, 0.1));
	expected = tcolor(0.9, 0.2, 0.04);
	mu_assert_tuple_eq(expected, result);
}

MU_TEST_SUITE(colors_suite) {
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(tcolor_tst);
	MU_RUN_TEST(add_color_tst);
	MU_RUN_TEST(sub_color_tst);
	MU_RUN_TEST(multplying_color_tst);

}

int main(int argc, char *argv[]) {
	MU_RUN_SUITE(colors_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}

