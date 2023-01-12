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

	result_db = mx_3by3_cofactor(matrix, 0, 0);
	mu_assert_double_eq(-12, result_db);

	result_db = mx_3by3_cofactor(matrix, 1, 0);
	mu_assert_double_eq(-25, result_db);
}

MU_TEST(determinant_3by3_tst){
	set_matrix(&matrix, (t_set_matrix){
		1, 2, 6, 0,
		-5, 8, -4, 0,
		2, 6, 4, 0,
		0, 0, 0, 0
	});

	result_db = mx_3by3_cofactor(matrix, 0, 0);
	mu_assert_double_eq(56, result_db);

	result_db = mx_3by3_cofactor(matrix, 0, 1);
	mu_assert_double_eq(12, result_db);

	result_db = mx_3by3_cofactor(matrix, 0, 2);
	mu_assert_double_eq(-46, result_db);

	result_db = mx_3by3_determinant(matrix);
	mu_assert_double_eq(-196, result_db);
}

MU_TEST(determinant_4by4_tst){
	set_matrix(&matrix, (t_set_matrix){
		-2, -8, 3, 5,
		-3, 1, 7, 3,
		1, 2, -9, 6,
		-6, 7, 7, -9
	});

	result_db = mx_4by4_cofactor(matrix, 0, 0);
	mu_assert_double_eq(690, result_db);

	result_db = mx_4by4_cofactor(matrix, 0, 1);
	mu_assert_double_eq(447, result_db);

	result_db = mx_4by4_cofactor(matrix, 0, 2);
	mu_assert_double_eq(210, result_db);

	result_db = mx_4by4_cofactor(matrix, 0, 3);
	mu_assert_double_eq(51, result_db);

	result_db = mx_4by4_determinant(matrix);
	mu_assert_double_eq(-4071, result_db);
}

MU_TEST_SUITE(matrix_ops_tst) {
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(determinant_2by2_tst);
	MU_RUN_TEST(swtich_row_tst);
	MU_RUN_TEST(swtich_column_tst);
	MU_RUN_TEST(submatrix_3by3_tst);
	MU_RUN_TEST(submatrix_4by4_tst);
	MU_RUN_TEST(minor_3by3_test);
	MU_RUN_TEST(cofactor_tst);
	MU_RUN_TEST(determinant_3by3_tst);
	MU_RUN_TEST(determinant_4by4_tst);
}

int main(int argc, char *argv[]) {
	MU_RUN_SUITE(matrix_ops_tst);
	MU_REPORT();
	return MU_EXIT_CODE;
}
