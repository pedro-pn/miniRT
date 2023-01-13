#include "../test.h"

t_matrix	matrix;
t_matrix	mx1;
t_matrix	mx2;
t_matrix	result;
t_matrix	expected;
t_matrix	transform;
t_p3d		_point;
t_p3d		result_point;
t_v3d		_vector;
t_v3d		result_vector;


void test_setup(void) {
}

void test_teardown(void) {
	/* Nothing */
}

MU_TEST(translation_tst) {
	translation(vector(5, -3, 2), &transform);
	_point = point(-3, 4, 5);
	result_point = mx_tuple_product(transform, _point);

	mu_assert_tuple_eq(point(2, 1, 7), result_point);
}

MU_TEST(inverse_translation_tst){
	translation(vector(5, -3, 2), &transform);
	mx_inverse(transform, &matrix);
	_point = point(-3, 4, 5);
	result_point = mx_tuple_product(matrix, _point);

	mu_assert_tuple_eq(point(-8, 7, 3), result_point);
}

MU_TEST(vector_translation_tst){
	translation(vector(5, -3, 2), &transform);
	_vector = vector(-3, 4, 5);
	result_vector = mx_tuple_product(transform, _vector);

	mu_assert_tuple_eq(_vector, result_vector);
}

MU_TEST(scaling_point_tst){
	scaling(vector(2, 3, 4), &transform);
	_point = point(-4, 6, 8);
	result_point = mx_tuple_product(transform, _point);

	mu_assert_tuple_eq(point(-8, 18, 32), result_point);
}

MU_TEST(scaling_vector_tst){
	scaling(vector(2, 3, 4), &transform);
	_vector = vector(-4, 6, 8);
	result_vector = mx_tuple_product(transform, _vector);

	mu_assert_tuple_eq(vector(-8, 18, 32), result_vector);
}

MU_TEST(inverse_scaling_tst){
	scaling(vector(2, 3, 4), &transform);
	mx_inverse(transform, &matrix);
	_vector = vector(-4, 6, 8);
	result_vector = mx_tuple_product(matrix, _vector);

	mu_assert_tuple_eq(vector(-2, 2, 2), result_vector);
}

MU_TEST(scaling_neg_tst){
	scaling(vector(-1, 1, 1), &transform);
	_point = point(2, 3, 4);
	result_point = mx_tuple_product(transform, _point);

	mu_assert_tuple_eq(point(-2, 3, 4), result_point);
}

// Scenario : Rotating a point around the x axis
// Given p ← point(0, 1, 0)
// And half_quarter ← rotation_x(π / 4)
// And full_quarter ← rotation_x(π / 2)
// Then half_quarter * p = point(0, √2/2, √2/2)
// And full_quarter * p = point(0, 0, 1)

MU_TEST(rotation_x_tst){
	rotation_x(MY_PI / 4, &transform);
	result_point = mx_tuple_product(transform, point(0, 1, 0));
	mu_assert_tuple_eq(point(0, sqrt(2) / 2, sqrt(2) / 2), result_point);

	rotation_x(MY_PI / 2, &transform);
	result_point = mx_tuple_product(transform, point(0, 1, 0));
	mu_assert_tuple_eq(point(0, 0, 1), result_point);

	rotation_x(MY_PI / 4, &transform);
	mx_inverse(transform, &matrix);
	result_point = mx_tuple_product(matrix, point(0, 1, 0));
	mu_assert_tuple_eq(point(0, sqrt(2) / 2, -sqrt(2) / 2), result_point);
}

MU_TEST(rotation_y_tst){
	rotation_y(MY_PI / 4, &transform);
	result_point = mx_tuple_product(transform, point(0, 0, 1));
	mu_assert_tuple_eq(point(sqrt(2) / 2, 0, sqrt(2) / 2), result_point);

	rotation_y(MY_PI / 2, &transform);
	result_point = mx_tuple_product(transform, point(0, 0, 1));
	mu_assert_tuple_eq(point(1, 0, 0), result_point);
}

// Scenario : Rotating a point around the z axis
// Given p ← point(0, 1, 0)
// And half_quarter ← rotation_z(π / 4)
// And full_quarter ← rotation_z(π / 2)
// Then half_quarter * p = point(-√2/2, √2/2, 0)
// And full_quarter * p = point(-1, 0, 0)

MU_TEST(rotation_z_tst){
	rotation_z(MY_PI / 4, &transform);
	result_point = mx_tuple_product(transform, point(0, 1, 0));
	mu_assert_tuple_eq(point(-sqrt(2) / 2, sqrt(2) / 2, 0), result_point);

	rotation_z(MY_PI / 2, &transform);
	result_point = mx_tuple_product(transform, point(0, 1, 0));
	mu_assert_tuple_eq(point(-1, 0, 0), result_point);
}

MU_TEST_SUITE(transformation_suite) {
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(translation_tst);
	MU_RUN_TEST(inverse_translation_tst);
	MU_RUN_TEST(vector_translation_tst);
	MU_RUN_TEST(scaling_point_tst);
	MU_RUN_TEST(scaling_vector_tst);
	MU_RUN_TEST(inverse_scaling_tst);
	MU_RUN_TEST(scaling_neg_tst);
	MU_RUN_TEST(rotation_x_tst);
	MU_RUN_TEST(rotation_y_tst);
	MU_RUN_TEST(rotation_z_tst);
}


int main(int argc, char *argv[]) {
	MU_RUN_SUITE(transformation_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
