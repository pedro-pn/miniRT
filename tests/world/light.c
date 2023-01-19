#include "../test.h"

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
t_c3d		intensity;
t_p3d		_position;
t_light		*_light;

void test_setup(void) {
}

void test_teardown(void) {
	/* Nothing */
}

// Scenario : A point light has a position and intensity
// Given intensity ← color(1, 1, 1)
// And position ← point(0, 0, 0)
// When light ← point_light(position, intensity)
// Then light.position = position
// And light.intensity = intensity

MU_TEST(point_light_tst){
	_light = light();
	point_light(point(0, 0,  0), tcolor(1, 1, 1));

	mu_assert_tuple_eq(point(0, 0, 0), _light->position);
	mu_assert_tuple_eq(tcolor(1, 1, 1), _light->color);
}

MU_TEST_SUITE(light_suite) {
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(point_light_tst);

}

int main(int argc, char *argv[]) {
	MU_RUN_SUITE(light_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
