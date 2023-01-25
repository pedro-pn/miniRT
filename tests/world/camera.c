#include "../test.h"

t_camera	*cam;
t_matrix	mx_rot;
t_matrix	mx_trans;
t_matrix	mx_expected;
t_ray		_ray;

void test_setup(void) {
	start_mlx();
}

void test_teardown(void) {
	/* Nothing */
	clean_program();
}

MU_TEST(camera_tst){
	set_camera(160, 120, MY_PI / 2);
	cam = camera();
	mx_identity(&mx_expected);

	mu_assert_int_eq(160, cam->hsize);
	mu_assert_int_eq(120, cam->vsize);
	mu_assert_double_eq(MY_PI / 2, cam->field_of_view);
	mu_check(matrix_compare(mx_expected, cam->transform) == true);
}

MU_TEST(horizontal_canvas_tst){
	set_camera(200, 125, MY_PI / 2);
	cam = camera();

	mu_assert_double_eq(0.01, cam->pixel_size);
}

MU_TEST(vertival_canvas_tst){
	set_camera(125, 200, MY_PI / 2);
	cam = camera();

	mu_assert_double_eq(0.01, cam->pixel_size);
}

MU_TEST(ray_center_canvas_tst){
	set_camera(201, 101, MY_PI / 2);
	cam = camera();
	_ray = ray_for_pixel(100, 50);

	mu_assert_tuple_eq(point(0, 0, 0), _ray.origin);
	mu_assert_tuple_eq(vector(0, 0, -1), _ray.direction);
}

MU_TEST(ray_corner_canvas_tst){
	set_camera(201, 101, MY_PI / 2);
	cam = camera();
	_ray = ray_for_pixel(0, 0);

	mu_assert_tuple_eq(point(0, 0, 0), _ray.origin);
	mu_assert_tuple_eq(vector(0.66519, 0.33259, -0.66851), _ray.direction);
}

MU_TEST(ray_transformed_camera_tst){
	set_camera(201, 101, MY_PI / 2);
	cam = camera();
	rotation_y(MY_PI / 4, &mx_rot);
	translation(vector(0, -2, 5), &mx_trans);
	mx_product(mx_rot, mx_trans, &cam->transform);
	_ray = ray_for_pixel(100, 50);

	mu_assert_tuple_eq(point(0, 2, -5), _ray.origin);
	mu_assert_tuple_eq(vector(sqrt(2) / 2, 0, -sqrt(2) / 2), _ray.direction);
}

MU_TEST_SUITE(camera_suite) {
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(camera_tst);
	MU_RUN_TEST(horizontal_canvas_tst);
	MU_RUN_TEST(vertival_canvas_tst);

	MU_RUN_TEST(ray_center_canvas_tst);
	MU_RUN_TEST(ray_corner_canvas_tst);
	MU_RUN_TEST(ray_transformed_camera_tst);
}

int main(int argc, char *argv[]) {
	MU_RUN_SUITE(camera_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
