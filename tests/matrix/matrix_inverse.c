#include "../test.h"

t_matrix	matrix;
t_matrix	mx1;
t_matrix	mx2;
t_matrix	inverse_b;
t_matrix	result;
t_matrix	expected;
t_t3d		result_tuple;
t_t3d		expected_tuple;
double		result_db;
double		expected_db;

void test_setup(void) {
}

void test_teardown(void) {
	/* Nothing */
}

MU_TEST(is_invertible_tst){
	set_matrix(&matrix, (t_set_matrix){
		6, 4, 4, 4,
		5, 5, 7, 6,
		4, -9, 3, -7,
		9, 1, 7, -6
	});

	mu_check(mx_is_invertible(matrix, 4));

	set_matrix(&matrix, (t_set_matrix){
		-4, 2, -2, -3,
		9, 6, 2, 6,
		0, -5, 1, -5,
		0, 0, 0, 0
	});
	mu_check(!mx_is_invertible(matrix, 4));
}

MU_TEST(inverse_tst){
	set_matrix(&matrix, (t_set_matrix){
		-5, 2, 6, -8,
		1, -5, 1, 8,
		7, 7, -6, -7,
		1, -3, 7, 4
	});
	set_matrix(&expected, (t_set_matrix){
		0.21805, 0.45113, 0.24060, -0.04511,
		-0.80827, -1.45677, -0.44361, 0.52068,
		-0.07895, -0.22368, -0.05263, 0.19737,
		-0.52256, -0.81391, -0.30075, 0.30639
	});
	mx_inverse(matrix, &result);
	
	mu_assert_double_eq(532, mx_determinant(matrix, 4));
	mu_assert_double_eq(-160, mx_cofactor(matrix, 4, 2, 3));
	mu_assert_double_eq((double) -160/532, result[3][2]);
	mu_assert_double_eq(105, mx_cofactor(matrix, 4, 3, 2));
	mu_assert_double_eq((double) 105/532, result[2][3]);
	mu_assert_double_eq(105, mx_cofactor(matrix, 4, 3, 2));
	mu_check(matrix_compare(expected, result));
	
}

MU_TEST(inverse_2nd_tst){
	set_matrix(&matrix, (t_set_matrix){
		9, 3, 0, 9,
		-5, -2, -6, -3,
		-4, 9, 6, 4,
		-7, 6, 6, 2
	});
	set_matrix(&expected, (t_set_matrix){
		-0.04074, -0.07778, 0.14444, -0.22222,
		-0.07778, 0.03333, 0.36667, -0.33333,
		-0.02901, -0.14630, -0.10926, 0.12963,
		0.17778, 0.06667, -0.26667, 0.33333
	});
	mx_inverse(matrix, &result);
	
	mu_check(matrix_compare(expected, result));
}

MU_TEST(inverse_3rd_tst){
	set_matrix(&matrix, (t_set_matrix){
		8, -5, 9, 2,
		7, 5, 6, 1,
		-6, 0, 9, 6,
		-3, 0, -9, -4
	});
	set_matrix(&expected, (t_set_matrix){
		-0.15385, -0.15385, -0.28205, -0.53846,
		-0.07692, 0.12308, 0.02564, 0.03077,
		0.35897, 0.35897, 0.43590, 0.92308,
		-0.69231, -0.69231, -0.76923, -1.92308
	});
	mx_inverse(matrix, &result);
	
	mu_check(matrix_compare(expected, result));
}

MU_TEST(inverse_multiply_tst){
	set_matrix(&mx1, (t_set_matrix){
		3, -9, 7, 3,
		3, -8, 2, -9,
		-4, 4, 4, 1,
		-6, 5, -1, 1
	});
	set_matrix(&mx2, (t_set_matrix){
		8, 2, 2, 2,
		3, -1, 7, 0,
		7, 0, 5, 4,
		6, -2, 0, 5
	});
	
	mx_product(mx1, mx2, &matrix);
	mx_inverse(mx2, &inverse_b);
	mx_product(matrix, inverse_b, &result);
	mu_check(matrix_compare(mx1, result));

}

MU_TEST_SUITE(inverse_suite) {
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(is_invertible_tst);
	MU_RUN_TEST(inverse_tst);
	MU_RUN_TEST(inverse_2nd_tst);
	MU_RUN_TEST(inverse_3rd_tst);
	MU_RUN_TEST(inverse_multiply_tst);
}

int main(int argc, char *argv[]) {
	MU_RUN_SUITE(inverse_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
