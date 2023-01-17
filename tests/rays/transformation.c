#include "../test.h"

t_ray		_ray;
t_ray		ray_result;
t_matrix	mx_trans;
t_object	*_sphere;
t_matrix	mx_id;
t_intxs		xs;
t_intx		*inter;

void test_setup(void) {
}

void test_teardown(void) {
	/* Nothing */
}

MU_TEST(trans_ray_tst) {
	_ray = ray(point(1, 2, 3), vector(0, 1, 0));
	translation(vector(3, 4, 5), &mx_trans);
	ray_result = transform(mx_trans, _ray);

	mu_assert_tuple_eq(point(4, 6, 8), ray_result.origin);
	mu_assert_tuple_eq(vector(0, 1, 0), ray_result.direction);
}

MU_TEST(scaling_ray_tst) {
	_ray = ray(point(1, 2, 3), vector(0, 1, 0));
	scaling(vector(2, 3, 4), &mx_trans);
	ray_result = transform(mx_trans, _ray);

	mu_assert_tuple_eq(point(2, 6, 12), ray_result.origin);
	mu_assert_tuple_eq(vector(0, 3, 0), ray_result.direction);
}

// Scenario : A sphere's default transformation
// Given s ← sphere()
// Then s.transform = identity_matrix

MU_TEST(default_trans_sphere_tst){
	_sphere = sphere();
	mx_identity(&mx_id);

	mu_check(matrix_compare(mx_id, _sphere->transform));
}
// Scenario : Changing a sphere's transformation
// Given s ← sphere()
// And t ← translation(2, 3, 4)
// When set_transform(s, t)
// Then s.transform = t

MU_TEST(sphere_transf_tst){
	_sphere = sphere();
	translation(vector(2, 3, 4), &_sphere->transform);
	translation(vector(2, 3, 4), &mx_trans);
	
	mu_check(matrix_compare(mx_trans, _sphere->transform));
}

// Scenario : Intersecting a scaled sphere with a ray
// Given r ← ray(point(0, 0, -5), vector(0, 0, 1))
// And s ← sphere()
// When set_transform(s, scaling(2, 2, 2))
// And xs ← intersect(s, r)
// Then xs.count = 2
// And xs[0].t = 3
// And xs[1].t = 7

MU_TEST(intersect_scaled_sphere_tst){
	_ray = ray(point(0, 0, -5), vector(0, 0, 1));
	_sphere = sphere();
	scaling(vector(2, 2, 2), &_sphere->transform);
	xs = intersect(_sphere, _ray);

	mu_assert_int_eq(2, xs.count);

	inter = xs.intersections->content;
	mu_assert_double_eq(3, inter->t);

	inter = xs.intersections->next->content;
	mu_assert_double_eq(7, inter->t);
}

// Scenario : Intersecting a translated sphere with a ray
// Given r ← ray(point(0, 0, -5), vector(0, 0, 1))
// And s ← sphere()
// When set_transform(s, translation(5, 0, 0))
// And xs ← intersect(s, r)
// Then xs.count = 0

MU_TEST(intersect_translated_sphere_tst){
	_ray = ray(point(0, 0, -5), vector(0, 0, 1));
	_sphere = sphere();
	translation(vector(5, 0, 0), &_sphere->transform);
	xs = intersect(_sphere, _ray);

	mu_assert_int_eq(0, xs.count);
}

MU_TEST_SUITE(ray_transf_suite) {
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(trans_ray_tst);
	MU_RUN_TEST(scaling_ray_tst);
	MU_RUN_TEST(default_trans_sphere_tst);
	MU_RUN_TEST(sphere_transf_tst);
	MU_RUN_TEST(intersect_scaled_sphere_tst);
	MU_RUN_TEST(intersect_translated_sphere_tst);

}

int main(int argc, char *argv[]) {
	MU_RUN_SUITE(ray_transf_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}

