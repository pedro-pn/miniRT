#include "../test.h"

t_material	mat;
t_object	*obj;
t_intx		inter;
t_ray		r;
t_comp		comps;
t_world		*w;
t_c3d		result_color;

void test_setup(void) {
	default_world();
	point_light(point(-10, 10, -10), tcolor(1, 1, 1));
}

void test_teardown(void) {
	/* Nothing */
	ft_lstclear(&world()->objects, free);
}

MU_TEST(reflection_tst) {
	mat = material();

	mu_assert_double_eq(0.0,  mat.reflective);
}

MU_TEST(reflection_vector_tst){
	obj = plane();
	r = ray(point(0, 1, -1), vector(0, -sqrt(2)/2, sqrt(2)/2));
	inter = (t_intx){sqrt(2), obj};
	comps = prepare_computations(inter, r);
	free(obj);

	mu_assert_tuple_eq(vector(0, sqrt(2) / 2, sqrt(2) / 2), comps.reflectv);

}

MU_TEST(nonreflective_material_tst){
	w = world();
	r = ray(point(0, 0, 0), vector(0, 0, 1));
	obj = w->objects->next->content;
	obj->material.ambient = 1;
	inter = (t_intx){1, obj};
	comps = prepare_computations(inter, r);
	result_color = reflected_color(comps);

	mu_assert_tuple_eq(tcolor(0, 0, 0), result_color);
}

MU_TEST(reflective_material_tst){
	obj = plane();
	obj->material.reflective = 0.5;
	translation(vector(0, -1, 0), &obj->transform);
	create_object(obj);
	r = ray(point(0, 0, -3), vector(0, -sqrt(2) / 2, sqrt(2) / 2));
	inter = (t_intx){sqrt(2.0), obj};
	comps = prepare_computations(inter, r);
	result_color = reflected_color(comps);

	mu_check((t_object *)world()->objects->next->next->content == obj);
	mu_assert_tuple_eq(tcolor(0.19032, 0.2379, 0.14274), result_color);
}

MU_TEST(reflective_material_shade_hit_tst){
	obj = plane();
	obj->material.reflective = 0.5;
	translation(vector(0, -1, 0), &obj->transform);
	create_object(obj);
	r = ray(point(0, 0, -3), vector(0, -sqrt(2) / 2, sqrt(2) / 2));
	inter = (t_intx){sqrt(2.0), obj};
	comps = prepare_computations(inter, r);
	result_color = shade_hit(comps);

	mu_check((t_object *)world()->objects->next->next->content == obj);
	mu_assert_tuple_eq(tcolor(0.87677, 0.92436, 0.82918), result_color);
}

MU_TEST_SUITE(reflection_suite) {
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(reflection_tst);
	MU_RUN_TEST(reflection_vector_tst);
	MU_RUN_TEST(nonreflective_material_tst);
	MU_RUN_TEST(reflective_material_tst);
	MU_RUN_TEST(reflective_material_shade_hit_tst);
}

int main(int argc, char *argv[]) {
	MU_RUN_SUITE(reflection_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
