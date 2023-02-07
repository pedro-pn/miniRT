#include "../test.h"

t_matrix	matrix;
t_matrix	mx1;
t_matrix	mx2;
t_matrix	result;
t_matrix	expected;
t_matrix	_transform;
t_matrix	mx_rotation;
t_matrix	mx_translation;
t_matrix	mx_scaling;
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
	translation(vector(5, -3, 2), &_transform);
	_point = point(-3, 4, 5);
	result_point = mx_tuple_product(_transform, _point);

	assert_tuple_eq(point(2, 1, 7), result_point);
}

MU_TEST(inverse_translation_tst){
	translation(vector(5, -3, 2), &_transform);
	mx_inverse(_transform, &matrix);
	_point = point(-3, 4, 5);
	result_point = mx_tuple_product(matrix, _point);

	assert_tuple_eq(point(-8, 7, 3), result_point);
}

MU_TEST(vector_translation_tst){
	translation(vector(5, -3, 2), &_transform);
	_vector = vector(-3, 4, 5);
	result_vector = mx_tuple_product(_transform, _vector);

	assert_tuple_eq(_vector, result_vector);
}

MU_TEST(scaling_point_tst){
	scaling(vector(2, 3, 4), &_transform);
	_point = point(-4, 6, 8);
	result_point = mx_tuple_product(_transform, _point);

	assert_tuple_eq(point(-8, 18, 32), result_point);
}

MU_TEST(scaling_vector_tst){
	scaling(vector(2, 3, 4), &_transform);
	_vector = vector(-4, 6, 8);
	result_vector = mx_tuple_product(_transform, _vector);

	assert_tuple_eq(vector(-8, 18, 32), result_vector);
}

MU_TEST(inverse_scaling_tst){
	scaling(vector(2, 3, 4), &_transform);
	mx_inverse(_transform, &matrix);
	_vector = vector(-4, 6, 8);
	result_vector = mx_tuple_product(matrix, _vector);

	assert_tuple_eq(vector(-2, 2, 2), result_vector);
}

MU_TEST(scaling_neg_tst){
	scaling(vector(-1, 1, 1), &_transform);
	_point = point(2, 3, 4);
	result_point = mx_tuple_product(_transform, _point);

	assert_tuple_eq(point(-2, 3, 4), result_point);
}

MU_TEST(rotation_x_tst){
	rotation_x(MY_PI / 4, &_transform);
	result_point = mx_tuple_product(_transform, point(0, 1, 0));
	assert_tuple_eq(point(0, sqrt(2) / 2, sqrt(2) / 2), result_point);

	rotation_x(MY_PI / 2, &_transform);
	result_point = mx_tuple_product(_transform, point(0, 1, 0));
	assert_tuple_eq(point(0, 0, 1), result_point);

	rotation_x(MY_PI / 4, &_transform);
	mx_inverse(_transform, &matrix);
	result_point = mx_tuple_product(matrix, point(0, 1, 0));
	assert_tuple_eq(point(0, sqrt(2) / 2, -sqrt(2) / 2), result_point);
}

MU_TEST(rotation_y_tst){
	rotation_y(MY_PI / 4, &_transform);
	result_point = mx_tuple_product(_transform, point(0, 0, 1));
	assert_tuple_eq(point(sqrt(2) / 2, 0, sqrt(2) / 2), result_point);

	rotation_y(MY_PI / 2, &_transform);
	result_point = mx_tuple_product(_transform, point(0, 0, 1));
	assert_tuple_eq(point(1, 0, 0), result_point);
}

MU_TEST(rotation_z_tst){
	rotation_z(MY_PI / 4, &_transform);
	result_point = mx_tuple_product(_transform, point(0, 1, 0));
	assert_tuple_eq(point(-sqrt(2) / 2, sqrt(2) / 2, 0), result_point);

	rotation_z(MY_PI / 2, &_transform);
	result_point = mx_tuple_product(_transform, point(0, 1, 0));
	assert_tuple_eq(point(-1, 0, 0), result_point);
}

MU_TEST(shearing_tst){
	shearing((t_shearing){1, 0, 0, 0, 0, 0}, &_transform);
	result_point = mx_tuple_product(_transform, point(2, 3, 4));
	assert_tuple_eq(point(5, 3, 4), result_point);

	shearing((t_shearing){0, 1, 0, 0, 0, 0}, &_transform);
	result_point = mx_tuple_product(_transform, point(2, 3, 4));
	assert_tuple_eq(point(6, 3, 4), result_point);

	shearing((t_shearing){0, 0, 1, 0, 0, 0}, &_transform);
	result_point = mx_tuple_product(_transform, point(2, 3, 4));
	assert_tuple_eq(point(2, 5, 4), result_point);

	shearing((t_shearing){0, 0, 0, 1, 0, 0}, &_transform);
	result_point = mx_tuple_product(_transform, point(2, 3, 4));
	assert_tuple_eq(point(2, 7, 4), result_point);

	shearing((t_shearing){0, 0, 0, 0, 1, 0}, &_transform);
	result_point = mx_tuple_product(_transform, point(2, 3, 4));
	assert_tuple_eq(point(2, 3, 6), result_point);

	shearing((t_shearing){0, 0, 0, 0, 0, 1}, &_transform);
	result_point = mx_tuple_product(_transform, point(2, 3, 4));
	assert_tuple_eq(point(2, 3, 7), result_point);
}

MU_TEST(individual_transformations_tst){
	_point = point(1, 0, 1);
	rotation_x(MY_PI / 2, &mx_rotation);
	scaling(vector(5, 5, 5), &mx_scaling);
	translation(vector(10, 5, 7), &mx_translation);

	result_point = mx_tuple_product(mx_rotation, _point);
	assert_tuple_eq(point(1, -1, 0), result_point);

	result_point = mx_tuple_product(mx_scaling, result_point);
	assert_tuple_eq(point(5, -5, 0), result_point);
	
	result_point = mx_tuple_product(mx_translation, result_point);
	assert_tuple_eq(point(15, 0, 7), result_point);
}

MU_TEST(chained_transformation_tst){
	_point = point(1, 0, 1);
	rotation_x(MY_PI / 2, &mx_rotation);
	scaling(vector(5, 5, 5), &mx_scaling);
	translation(vector(10, 5, 7), &mx_translation);
	mx_product(mx_translation, mx_scaling, &matrix);
	mx_product(matrix, mx_rotation, &_transform);
	result_point = mx_tuple_product(_transform, _point);

	assert_tuple_eq(point(15, 0, 7), result_point);
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
	MU_RUN_TEST(shearing_tst);
	MU_RUN_TEST(individual_transformations_tst);
	MU_RUN_TEST(chained_transformation_tst);
}

int main(int argc, char *argv[]) {
	MU_RUN_SUITE(transformation_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
