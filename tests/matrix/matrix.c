#include "../test.h"

t_matrix	matrix;
t_matrix	mx_a;
t_matrix	mx_b;

void test_setup(void) {
}

void test_teardown(void) {
	/* Nothing */
}

MU_TEST(set_matrix_tst) {
	set_matrix(&matrix, (t_set_matrix){
		1, 2, 3, 4,
		5.5, 6.5, 7.5, 8.5,
		9 , 10 , 11 , 12 ,
		13.5 , 14.5 , 15.5 , 16.5});
	mu_assert_double_eq(1, matrix[0][0]);
	mu_assert_double_eq(4, matrix[0][3]);
	mu_assert_double_eq(5.5, matrix[1][0]);
	mu_assert_double_eq(7.5, matrix[1][2]);
	mu_assert_double_eq(11, matrix[2][2]);
	mu_assert_double_eq(13.5, matrix[3][0]);
	mu_assert_double_eq(15.5, matrix[3][2]);
}

MU_TEST(set_2by2_mx_tst){
	set_matrix(&matrix, (t_set_matrix){
		-3, 5, 0, 0,
		1, -2, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0
	});
	mu_assert_double_eq(-3, matrix[0][0]);
	mu_assert_double_eq(5, matrix[0][1]);
	mu_assert_double_eq(1, matrix[1][0]);
	mu_assert_double_eq(-2, matrix[1][1]);
}

MU_TEST(set_3by3_mx_tst){
	set_matrix(&matrix, (t_set_matrix){
		-3, 5, 0, 0,
		1, -2, -7, 0,
		0, 1, 1, 0,
		0, 0, 0, 0
	});
	mu_assert_double_eq(-3, matrix[0][0]);
	mu_assert_double_eq(5, matrix[0][1]);
	mu_assert_double_eq(0, matrix[0][2]);
	mu_assert_double_eq(1, matrix[1][0]);
	mu_assert_double_eq(-2, matrix[1][1]);
	mu_assert_double_eq(-7, matrix[1][2]);
	mu_assert_double_eq(0, matrix[2][0]);
	mu_assert_double_eq(1, matrix[2][1]);
	mu_assert_double_eq(1, matrix[2][2]);
}

MU_TEST(equal_matrix_tst){
	set_matrix(&mx_a, (t_set_matrix){
		1, 2, 3, 4, 
		5, 6, 7, 8, 
		9, 8, 7, 6, 
		5, 4, 3, 2
	});
	set_matrix(&mx_b, (t_set_matrix){
		1, 2, 3, 4, 
		5, 6, 7, 8, 
		9, 8, 7, 6, 
		5, 4, 3, 2
	});
	mu_check(matrix_compare(mx_a, mx_b));
}

MU_TEST(diff_matrix_tst){
	set_matrix(&mx_a, (t_set_matrix){
		1, 2, 3, 4, 
		5, 6, 7, 8, 
		9, 8, 7, 6, 
		5, 4, 3, 2
	});
	set_matrix(&mx_b, (t_set_matrix){
		2, 3, 4, 5,
		6, 7, 8, 9,
		8, 7, 6, 5,
		4, 3, 2, 1
	});
	mu_check(!matrix_compare(mx_a, mx_b));
}


MU_TEST_SUITE(matrix_suite) {
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(set_matrix_tst);
	MU_RUN_TEST(set_2by2_mx_tst);
	MU_RUN_TEST(set_3by3_mx_tst);
	MU_RUN_TEST(equal_matrix_tst);
	MU_RUN_TEST(diff_matrix_tst);

}

int main(int argc, char *argv[]) {
	MU_RUN_SUITE(matrix_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}

