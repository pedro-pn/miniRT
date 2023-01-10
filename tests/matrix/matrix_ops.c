#include "../test.h"

t_matrix	matrix;
t_matrix	mx1;
t_matrix	mx2;
t_matrix	result;
t_matrix	expected;
t_t3d		result_tuple;
t_t3d		expected_tuple;

void test_setup(void) {
}

void test_teardown(void) {
	/* Nothing */
}

MU_TEST(mx_multiplying_tst) {
	set_matrix(&mx1, (t_set_matrix){
		1, 2, 3, 4, 
		5, 6, 7, 8, 
		9, 8, 7, 6, 
		5, 4, 3, 2
	});
	set_matrix(&mx2, (t_set_matrix){
		-2, 1, 2, 3,
		3, 2, 1, -1,
		4, 3, 6, 5,
		1, 2, 7, 8
	});
	set_matrix(&expected, (t_set_matrix){
		20, 22, 50, 48,
		44, 54, 114, 108,
		40, 58, 110, 102,
		16, 26, 46, 42
	});
	mx_product(mx1, mx2, &result);
	mu_check(matrix_compare(result, expected));
}

// Scenario : A matrix multiplied by a tuple
// Given the following matrix A:
//, 1 | 2 | 3 | 4 |
// | 2 | 4 | 4 | 2 |
// | 8 | 6 | 4 | 1 |
// | 0 | 0 | 0 | 1 |
// And b ← tuple(1, 2, 3, 1)
// Then A * b = tuple(18, 24, 33, 1)

MU_TEST(mx_tuple_multiply_tst){
	set_matrix(&matrix, (t_set_matrix){
		1, 2, 3, 4,
		2, 4, 4, 2,
		8, 6, 4, 1,
		0, 0, 0, 1
	});
	result_tuple = mx_tuple_product(matrix, tuple_3d(1, 2, 3, 1));
	expected_tuple = tuple_3d(18, 24, 33, 1);
	mu_assert_tuple_eq(expected_tuple, result_tuple);
}

MU_TEST(identity_tst){
	mx_identity(&matrix);
	set_matrix(&expected, (t_set_matrix){
		1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1
	});
	mu_check(matrix_compare(matrix, expected));

	set_matrix(&mx1, (t_set_matrix){
		0, 1, 2, 4,
		1, 2, 4, 8,
		2, 4, 8, 16,
		4, 8, 16, 32
	});
	mx_product(mx1, matrix, &result);
	mu_check(matrix_compare(mx1, result));
}

MU_TEST(transpose_tst){
	set_matrix(&matrix, (t_set_matrix){
		0, 9, 3, 0,
		9, 8, 0, 8,
		1, 8, 5, 3,
		0, 0, 5, 8
	});
	set_matrix(&expected, (t_set_matrix){
		0, 9, 1, 0,
		9, 8, 8, 0,
		3, 0, 5, 5,
		0, 8, 3, 8
	});
	mx_transpose(matrix, &result);
	mu_check(matrix_compare(expected, result));
}

MU_TEST_SUITE(matrix_ops_tst) {
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(mx_multiplying_tst);
	MU_RUN_TEST(mx_tuple_multiply_tst);
	MU_RUN_TEST(identity_tst);
	MU_RUN_TEST(transpose_tst);
}


int main(int argc, char *argv[]) {
	MU_RUN_SUITE(matrix_ops_tst);
	MU_REPORT();
	return MU_EXIT_CODE;
}

