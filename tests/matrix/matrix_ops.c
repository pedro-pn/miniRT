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

MU_TEST(mx_tuple_multiply_tst){
	set_matrix(&matrix, (t_set_matrix){
		1, 2, 3, 4,
		2, 4, 4, 2,
		8, 6, 4, 1,
		0, 0, 0, 1
	});
	result_tuple = mx_tuple_product(matrix, tuple_3d(1, 2, 3, 1));
	expected_tuple = tuple_3d(18, 24, 33, 1);
	assert_tuple_eq(expected_tuple, result_tuple);
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

MU_TEST(determinant_2by2_tst){
	set_matrix(&matrix, (t_set_matrix){
		1, 5, 0, 0,
		-3, 2, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0
	});
	result_db = mx_2by2_determinant(matrix);
	mu_assert_double_eq(17, result_db);
}

MU_TEST(swtich_row_tst){
	set_matrix(&matrix, (t_set_matrix){
		0, 9, 3, 0,
		9, 8, 0, 8,
		1, 8, 5, 3,
		0, 0, 5, 8
	});
	set_matrix(&expected, (t_set_matrix){
		0, 9, 3, 0,
		0, 0, 5, 8,
		1, 8, 5, 3,
		9, 8, 0, 8
	});
	mx_switch_rows(&matrix, 1, 3);

	mu_check(matrix_compare(matrix, expected));

	set_matrix(&matrix, (t_set_matrix){
		0, 9, 3, 0,
		9, 8, 0, 8,
		1, 8, 5, 3,
		0, 0, 5, 8
	});
	set_matrix(&expected, (t_set_matrix){
		1, 8, 5, 3,
		9, 8, 0, 8,
		0, 9, 3, 0,
		0, 0, 5, 8
	});
	mx_switch_rows(&matrix, 0, 2);
	
	mu_check(matrix_compare(matrix, expected));
}

MU_TEST(swtich_column_tst){
	set_matrix(&matrix, (t_set_matrix){
		0, 9, 3, 0,
		9, 8, 0, 8,
		1, 8, 5, 3,
		0, 0, 5, 8
	});
	set_matrix(&expected, (t_set_matrix){
		3, 9, 0, 0,
		0, 8, 9, 8,
		5, 8, 1, 3,
		5, 0, 0, 8
	});
	mx_switch_columns(&matrix, 0, 2);

	mu_check(matrix_compare(matrix, expected));

	set_matrix(&matrix, (t_set_matrix){
		0, 9, 3, 0,
		9, 8, 0, 8,
		1, 8, 5, 3,
		0, 0, 5, 8
	});
	set_matrix(&expected, (t_set_matrix){
		0, 0, 3, 9,
		9, 8, 0, 8,
		1, 3, 5, 8,
		0, 8, 5, 0
	});
	mx_switch_columns(&matrix, 1, 3);
	
	mu_check(matrix_compare(matrix, expected));
}

MU_TEST(submatrix_3by3_tst){
	set_matrix(&matrix, (t_set_matrix){
		1.0, 5.0, 0, 0,
		-3.0, 2.0, 7.0, 0,
		0, 6.0, -3.0, 0,
		0, 0, 0, 0
	});
	mx_submatrix(matrix, 0, 2, &result);
	set_matrix(&expected, (t_set_matrix){
		-3.0, 2.0, 0, 0,
		0, 6.0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0
	});
	mu_check(matrix_compare(expected, result));
}

MU_TEST(submatrix_4by4_tst){
	set_matrix(&matrix, (t_set_matrix){
		-6, 1, 1, 6,
		-8, 5, 8, 6,
		-1, 0, 8, 2,
		-7, 1, -1, 1
	});
	set_matrix(&expected, (t_set_matrix){
		-6, 1, 6, 0,
		-8, 8, 6, 0,
		-7, -1, 1, 0,
		0, 0, 0, 0
	});
	mx_submatrix(matrix, 2, 1, &result);

	mu_check(matrix_compare(expected, result));
}

MU_TEST(minor_3by3_test){
	set_matrix(&matrix, (t_set_matrix){
		3, 5, 0, 0,
		2, -1, -7, 0,
		6, -1, 5, 0,
		0, 0, 0, 0
	});
	result_db = mx_minor(matrix, 1, 0);
	
	mu_assert_double_eq(25, result_db);
}

MU_TEST(cofactor_tst){
	set_matrix(&matrix, (t_set_matrix){
		3, 5, 0, 0,
		2, -1, -7, 0,
		6, -1, 5, 0,
		0, 0, 0, 0
	});

	result_db = mx_cofactor(matrix, 3, 0, 0);
	mu_assert_double_eq(-12, result_db);

	result_db = mx_cofactor(matrix, 3, 1, 0);
	mu_assert_double_eq(-25, result_db);
}

MU_TEST_SUITE(matrix_ops_tst) {
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(mx_multiplying_tst);
	MU_RUN_TEST(mx_tuple_multiply_tst);
	MU_RUN_TEST(identity_tst);
	MU_RUN_TEST(transpose_tst);
	MU_RUN_TEST(determinant_2by2_tst);
	MU_RUN_TEST(swtich_row_tst);
	MU_RUN_TEST(swtich_column_tst);
	MU_RUN_TEST(submatrix_3by3_tst);
	MU_RUN_TEST(submatrix_4by4_tst);
	MU_RUN_TEST(minor_3by3_test);
	MU_RUN_TEST(cofactor_tst);
}


int main(int argc, char *argv[]) {
	MU_RUN_SUITE(matrix_ops_tst);
	MU_REPORT();
	return MU_EXIT_CODE;
}
