#include "../test.h"

t_world		*_world;
t_object	*_object;
t_list		*_objects;
t_object	*_sphere;
t_light		expected_light;
t_matrix	_matrix;
t_matrix	mx_expected;
t_matrix	expected_scal;
t_ray		_ray;
t_intxs		xs;
t_intx		*inter;
t_list		*intersections;
t_list		*node;
t_comp		comps;
t_c3d		result_color;
t_intx		intx;
t_view		_view;

void test_setup(void) {

}

void test_teardown(void) {
	/* Nothing */
}

MU_TEST(default_view_tst){
	_view.from = point(0, 0, 0);
	_view.to = point(0, 0, -1);
	_view.up = vector(0, 1, 0);
	view_transformation(_view, &_matrix);
	mx_identity(&mx_expected);

	mu_check(matrix_compare(mx_expected, _matrix) == true);
}

MU_TEST(view_z_positive_tst){
	_view.from = point(0, 0, 0);
	_view.to = point(0, 0, 1);
	_view.up = vector(0, 1, 0);
	view_transformation(_view, &_matrix);
	scaling(vector(-1, 1, -1), &mx_expected);

	mu_check(matrix_compare(mx_expected, _matrix) == true);
}

MU_TEST(view_moves_world_tst){
	_view.from = point(0, 0, 8);
	_view.to = point(0, 0, 0);
	_view.up = vector(0, 1, 0);
	view_transformation(_view, &_matrix);
	translation(vector(0, 0, -8), &mx_expected);

	mu_check(matrix_compare(mx_expected, _matrix) == true);
}

MU_TEST(view_arbitratu_Tst){
	_view.from = point(1, 3, 2);
	_view.to = point(4, -2, 8);
	_view.up = vector(1, 1, 0);
	view_transformation(_view, &_matrix);
	set_matrix(&mx_expected, (t_set_matrix){
		-0.50709, 0.50709, 0.67612, -2.36643,
		0.76772, 0.60609, 0.12122, -2.82843,
		-0.35857, 0.59761, -0.71714, 0.00000,
		0.00000, 0.00000, 0.00000, 1.00000
	});

	mu_check(matrix_compare(mx_expected, _matrix) == true);
}

MU_TEST_SUITE(view_suite) {
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(default_view_tst);
	MU_RUN_TEST(view_z_positive_tst);
	MU_RUN_TEST(view_moves_world_tst);
	MU_RUN_TEST(view_arbitratu_Tst);

}

int main(int argc, char *argv[]) {
	MU_RUN_SUITE(view_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
