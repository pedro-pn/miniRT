#include "../test.h"

t_view		view;
t_rgb		_color;


void test_setup(void) {
	set_light(point(-10.0, 10.0, -10.0), 1.0);
	set_ambient_light(1.0, white_rgb());
	start_mlx();
}

void test_teardown(void) {
	/* Nothing */
	ft_lstclear(&world()->objects, free);
	clean_program();
	
}

MU_TEST(render_tst)
{
	default_world();
	set_camera(11, 11, MY_PI / 2);
	view.from = point(0, 0, -5);
	view.to = point(0, 0, 0);
	view.up = vector(0, 1, 0);
	view_transformation(view, &camera()->transform);
	render();
	_color = int_to_rgb(mlx_get_pixel_from_img(image(), 5, 5));

	mu_assert_int_eq(97, _color.r);
	mu_assert_int_eq(121, _color.g);
	mu_assert_int_eq(72, _color.b);

	// printf("Result_color: (%f, %f, %f)\n", result_color.x, result_color.y, result_color.z);
	// mu_assert_tuple_eq(tcolor(0.38066, 0.47583, 0.2855), result_color);
	
}

MU_TEST_SUITE(render_suite) {
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(render_tst);
}

int main(int argc, char *argv[]) {
	MU_RUN_SUITE(render_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}

