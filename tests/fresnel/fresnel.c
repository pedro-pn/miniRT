#include "../test.h"

t_object	*obj;
t_object	*_floor;
t_ray		r;
t_intxs		xs;
t_intx		*inter;
t_comp		comps;
t_object	*ball;
double		reflectance;
t_c3d		result_color;

void test_setup(void) {
	default_world();
	point_light(point(-10, 10, -10), white());
	obj = glass_sphere();

}

void test_teardown(void) {
	/* Nothing */
	free(obj);
	ft_lstclear(&xs.intersections, free);
	ft_lstclear(&world()->objects, free);
}

MU_TEST(schlick_total_reflection_tst){
	r = ray(point(0, 0, sqrt(2) / 2), vector(0, 1, 0));
	create_intersection(&xs, -sqrt(2) / 2, obj);
	create_intersection(&xs, sqrt(2) / 2, obj);
	comps = prepare_computations(xs.intersections->next->content, r, xs);
	reflectance = schlick(comps);

	mu_assert_double_eq(1.0, reflectance);
}

MU_TEST(schlick_perpendicular_tst){
	r = ray(point(0, 0, 0), vector(0, 1, 0));
	create_intersection(&xs, -1, obj);
	create_intersection(&xs, 1, obj);
	comps = prepare_computations(xs.intersections->next->content, r, xs);
	reflectance = schlick(comps);

	mu_assert_double_eq(0.04, reflectance);
}

MU_TEST(schlick_small_angle_tst){
	r = ray(point(0, 0.99, -2.0), vector(0, 0, 1.0));
	create_intersection(&xs, 1.8589, obj);
	comps = prepare_computations(xs.intersections->content, r, xs);
	reflectance = schlick(comps);

	mu_assert_double_eq(0.48873, reflectance);
}

MU_TEST(shade_hit_reflective_tst){
	r = ray(point(0, 0, -3), vector(0, -sqrt(2) / 2, sqrt(2) / 2));
	_floor = plane();
	translation(vector(0, -1, 0), &_floor->transform);
	_floor->material.reflective = 0.5;
	_floor->material.transparency = 0.5;
	_floor->material.refractive_index = 1.5;
	create_object(_floor);
	ball = sphere();
	ball->material.color = tcolor(1, 0, 0);
	ball->material.ambient = 0.5;
	translation(vector(0, -3.5, -0.5), &ball->transform);
	create_object(ball);
	create_intersection(&xs, sqrt(2), _floor);
	comps = prepare_computations(xs.intersections->content, r, xs);
	result_color = shade_hit(comps, 5);

	assert_tuple_eq(tcolor(0.93391, 0.69643, 0.69243), result_color);
	
}

MU_TEST_SUITE(fresnel_suite) {
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(schlick_total_reflection_tst);
	MU_RUN_TEST(schlick_perpendicular_tst);
	MU_RUN_TEST(schlick_small_angle_tst);
	MU_RUN_TEST(shade_hit_reflective_tst);

}

int main(int argc, char *argv[]) {
	MU_RUN_SUITE(fresnel_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}

