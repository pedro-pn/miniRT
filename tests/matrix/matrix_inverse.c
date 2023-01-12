#include "../test.h"

t_matrix	matrix;
t_matrix	mx1;
t_matrix	mx2;
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

// Scenario : Calculating the inverse of a matrix
// Given the following 4x4 matrix A:
// | -5 | 2 | 6 | -8 |
// | 1 | -5 | 1 | 8 |
// | 7 | 7 | -6 | -7 |
// | 1 | -3 | 7 | 4 |
// And B ← inverse(A)
// Then determinant(A) = 532
// And cofactor(A, 2, 3) = -160
// And B[3,2] = -160/532
// And cofactor(A, 3, 2) = 105
// And B[2,3] = 105/532
// And B is the following 4x4 matrix:
// | 0.21805 | 0.45113 | 0.24060 | -0.04511 |
// | -0.80827 | -1.45677 | -0.44361 | 0.52068 |
// | -0.07895 | -0.22368 | -0.05263 | 0.19737 |
// | -0.52256 | -0.81391 | -0.30075 | 0.30639 |

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

MU_TEST_SUITE(inverse_suite) {
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(is_invertible_tst);
	MU_RUN_TEST(inverse_tst);
}

int main(int argc, char *argv[]) {
	MU_RUN_SUITE(inverse_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
