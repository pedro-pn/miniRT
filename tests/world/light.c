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
t_v3d		eyev;
t_v3d		normalv;
t_material	_material;


void test_setup(void) {
	
}

void test_teardown(void) {
	/* Nothing */
}

MU_TEST(point_light_tst){
	_light = light();
	point_light(point(0, 0,  0), tcolor(1, 1, 1));

	mu_assert_tuple_eq(point(0, 0, 0), _light->position);
	mu_assert_tuple_eq(tcolor(1, 1, 1), _light->color);
}

MU_TEST(material_tst){
	_sphere = sphere();
	_sphere->material = material();

	mu_assert_tuple_eq(tcolor(1, 1, 1), _sphere->material.color);
	mu_assert_double_eq(0.1, _sphere->material.ambient);
	mu_assert_double_eq(0.9, _sphere->material.diffuse);
	mu_assert_double_eq(0.9, _sphere->material.specular);
	mu_assert_double_eq(200.0, _sphere->material.shininess);
	free(_sphere);
}

MU_TEST(eye_btwn_light_surf_tst){
	_position = point(0, 0, 0);
	eyev = vector(0, 0, -1);
	normalv = vector(0, 0, -1);
	point_light(point(0, 0, -10), tcolor(1, 1, 1));
	_material = material();
	intensity = lightning(_material, *light(), _position, eyev, normalv);

	mu_assert_tuple_eq(tcolor(1.9, 1.9, 1.9), intensity);
	
}

MU_TEST(eye_45_degree_tst){
	_position = point(0, 0, 0);
	eyev = vector(0, sqrt(2) / 2, -sqrt(2) / 2);
	normalv = vector(0, 0, -1);
	point_light(point(0, 0, -10), tcolor(1, 1, 1));
	_material = material();
	intensity = lightning(_material, *light(), _position, eyev, normalv);

	mu_assert_tuple_eq(tcolor(1.0, 1.0, 1.0), intensity);
}

MU_TEST(light_45_degree_tst){
	_position = point(0, 0, 0);
	eyev = vector(0, 0, -1);
	normalv = vector(0, 0, -1);
	point_light(point(0, 10, -10), tcolor(1, 1, 1));
	_material = material();
	intensity = lightning(_material, *light(), _position, eyev, normalv);

	mu_assert_tuple_eq(tcolor(0.7364, 0.7364, 0.7364), intensity);
}

MU_TEST(eye_in_light_path_tst){
	_position = point(0, 0, 0);
	eyev = vector(0, -sqrt(2) / 2, -sqrt(2) / 2);
	normalv = vector(0, 0, -1);
	point_light(point(0, 10, -10), tcolor(1, 1, 1));
	_material = material();
	intensity = lightning(_material, *light(), _position, eyev, normalv);

	mu_assert_tuple_eq(tcolor(1.6364, 1.6364, 1.6364), intensity);
}

MU_TEST(light_behind_surface_tst){
	_position = point(0, 0, 0);
	eyev = vector(0, 0, -1);
	normalv = vector(0, 0, -1);
	point_light(point(0, 0, 10), tcolor(1, 1, 1));
	_material = material();
	intensity = lightning(_material, *light(), _position, eyev, normalv);

	mu_assert_tuple_eq(tcolor(0.1, 0.1, 0.1), intensity);
}

MU_TEST_SUITE(light_suite) {
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(point_light_tst);
	MU_RUN_TEST(material_tst);
	MU_RUN_TEST(eye_btwn_light_surf_tst);
	MU_RUN_TEST(eye_45_degree_tst);
	MU_RUN_TEST(light_45_degree_tst);
	MU_RUN_TEST(eye_in_light_path_tst);
	MU_RUN_TEST(light_behind_surface_tst);

}

int main(int argc, char *argv[]) {
	MU_RUN_SUITE(light_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
