#include "../test.h"
#include <stdio.h>

t_ray		_ray;
t_ray		ray_result;
t_matrix	mx_trans;
t_matrix	mx_rot;
t_matrix	mx_scal;
t_object	*_sphere;
t_matrix	mx_id;
t_intxs		xs;
t_intx		*inter;
t_v3d		vec_result;

void test_setup(void) {
}

void test_teardown(void) {
	/* Nothing */
	free(_sphere);
}

MU_TEST(axial_sphere_normal_tst) {
	_sphere = sphere();

	vec_result = normal_at(*_sphere, point(1, 0, 0));
	mu_assert_tuple_eq(vector(1, 0, 0), vec_result);

	vec_result = normal_at(*_sphere, point(0, 1, 0));
	mu_assert_tuple_eq(vector(0, 1, 0), vec_result);

	vec_result = normal_at(*_sphere, point(0, 0, 1));
	mu_assert_tuple_eq(vector(0, 0, 1), vec_result);
}

MU_TEST(non_axial_normal_tst){
	double	sqrt_3by3 = sqrt(3) / 3;
	_sphere = sphere();

	vec_result = normal_at(*_sphere, point(sqrt_3by3, sqrt_3by3, sqrt_3by3));
	mu_assert_tuple_eq(vector(sqrt_3by3, sqrt_3by3, sqrt_3by3), vec_result);
}

MU_TEST(normal_is_normalized_tst){
	double	sqrt_3by3 = sqrt(3) / 3;
	_sphere = sphere();

	vec_result = normal_at(*_sphere, point(sqrt_3by3, sqrt_3by3, sqrt_3by3));
	mu_assert_tuple_eq(normalize(vector(sqrt_3by3, sqrt_3by3, sqrt_3by3)),
			vec_result);
}

MU_TEST(normal_translated_sphere_tst){
	_sphere = sphere();
	translation(vector(0, 1, 0), &_sphere->transform);

	vec_result = normal_at(*_sphere, point(0, 1.70711, -0.70711));
	mu_assert_tuple_eq(vector(0, 0.70711, -0.70711), vec_result);
}

MU_TEST(normal_transf_sphere_tst){
	_sphere = sphere();
	scaling(vector(1, 0.5, 1), &mx_scal);
	rotation_z(MY_PI / 5, &mx_rot);
	mx_product(mx_scal, mx_rot, &_sphere->transform);

	vec_result = normal_at(*_sphere, point(0, sqrt(2) / 2, -sqrt(2) / 2));
	mu_assert_tuple_eq(vector(0, 0.97014, -0.24254), vec_result);
}

MU_TEST_SUITE(shading_suite) {
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(axial_sphere_normal_tst);
	MU_RUN_TEST(non_axial_normal_tst);
	MU_RUN_TEST(normal_is_normalized_tst);
	MU_RUN_TEST(normal_translated_sphere_tst);
	MU_RUN_TEST(normal_transf_sphere_tst);
}

int main(int argc, char *argv[]) {
	MU_RUN_SUITE(shading_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
