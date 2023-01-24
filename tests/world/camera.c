#include "../test.h"

t_camera	*cam;
t_matrix	mx_expected;

void test_setup(void) {
}

void test_teardown(void) {
	/* Nothing */
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

MU_TEST_SUITE(camera_suite) {
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(camera_tst);
	MU_RUN_TEST(horizontal_canvas_tst);
	MU_RUN_TEST(vertival_canvas_tst);
}

int main(int argc, char *argv[]) {
	MU_RUN_SUITE(camera_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
