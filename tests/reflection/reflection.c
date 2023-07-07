#include "../test.h"
#include <setjmp.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

t_material	mat;
t_object	*obj;
t_intx		*inter;
t_ray		r;
t_comp		comps;
t_world		*w;
t_c3d		result_color;
t_object	*lower;
t_object	*upper;
t_bool		is_finished;
jmp_buf		buf;
t_intxs		xs;

void test_setup(void) {
	default_world();
	set_light(point(-10, 10, -10), 1.0);
	set_ambient_light(1.0, white_rgb());
	xs.intersections = NULL;
}

void test_teardown(void) {
	/* Nothing */
	ft_lstclear(&world()->objects, free);
	ft_lstclear(&xs.intersections, free);
}

MU_TEST(reflection_tst) {
	mat = material();

	mu_assert_double_eq(0.0,  mat.reflective);
}

MU_TEST(reflection_vector_tst){
	obj = plane();
	r = ray(point(0, 1, -1), vector(0, -sqrt(2)/2, sqrt(2)/2));
	create_intersection(&xs, sqrt(2), obj);
	comps = prepare_computations(xs.intersections->content, r, xs);
	free(obj);

	assert_tuple_eq(vector(0, sqrt(2) / 2, sqrt(2) / 2), comps.reflectv);

}

MU_TEST(nonreflective_material_tst){
	w = world();
	r = ray(point(0, 0, 0), vector(0, 0, 1));
	obj = w->objects->next->content;
	obj->material.ambient = 1;
	create_intersection(&xs, 1, obj);
	comps = prepare_computations(xs.intersections->content, r, xs);
	result_color = reflected_color(comps, 1);

	assert_tuple_eq(tcolor(0, 0, 0), result_color);
}

MU_TEST(reflective_material_tst){
	obj = plane();
	obj->material.reflective = 0.5;
	translation(vector(0, -1, 0), &obj->transform);
	create_object(obj);
	r = ray(point(0, 0, -3), vector(0, -sqrt(2) / 2, sqrt(2) / 2));
	create_intersection(&xs, sqrt(2.0), obj);
	comps = prepare_computations(xs.intersections->content, r, xs);
	result_color = reflected_color(comps, 1);

	mu_check((t_object *)world()->objects->next->next->content == obj);
	assert_tuple_eq(tcolor(0.19032, 0.2379, 0.14274), result_color);
}

MU_TEST(reflective_material_shade_hit_tst){
	obj = plane();
	obj->material.reflective = 0.5;
	translation(vector(0, -1, 0), &obj->transform);
	create_object(obj);
	r = ray(point(0, 0, -3), vector(0, -sqrt(2) / 2, sqrt(2) / 2));
	create_intersection(&xs, sqrt(2.0), obj);
	comps = prepare_computations(xs.intersections->content, r, xs);
	result_color = shade_hit(comps, 1);

	mu_check((t_object *)world()->objects->next->next->content == obj);
	assert_tuple_eq(tcolor(0.87677, 0.92436, 0.82918), result_color);
}

// void catch_segfault(int sig) {
//   longjmp(buf, 1);
// }

// void test_infinite_recursion(t_ray ray) {
//   if (setjmp(buf) == 0) {
//     signal(SIGSEGV, catch_segfault);
//     color_at(ray, 0);
//   } else {
//     // We  back here because the signal was raised
// 	is_finished = true;
//     printf("Test passed\n");
//   }
// }

// MU_TEST(mutually_reflective_surfaces_tst){
// 	is_finished = false;
// 	point_light(point(0, 0, 0), tcolor(1, 1, 1));
// 	lower = plane();
// 	lower->material.reflective = 1;
// 	translation(vector(0, -1, 0), &lower->transform);
// 	upper = plane();
// 	upper->material.reflective = 1;
// 	translation(vector(0, 1, 0), &upper->transform);
// 	create_object(lower);
// 	create_object(upper);
// 	r = ray(point(0, 0, 0), vector(0, 1, 0));
// 	test_infinite_recursion(r);

// 	mu_check(is_finished == true);
// }

MU_TEST(reflection_recursive_depth_tst){
	obj = plane();
	obj->material.reflective = 0.5;
	translation(vector(0, -1, 0), &obj->transform);
	create_object(obj);
	r = ray(point(0, 0, -3), vector(0, -sqrt(2) / 2, sqrt(2) / 2));
	create_intersection(&xs, sqrt(2.0), obj);
	comps = prepare_computations(xs.intersections->content, r, xs);
	result_color = reflected_color(comps, 0);

	assert_tuple_eq(black(), result_color);
}

MU_TEST_SUITE(reflection_suite) {
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(reflection_tst);
	MU_RUN_TEST(reflection_vector_tst);
	MU_RUN_TEST(nonreflective_material_tst);
	MU_RUN_TEST(reflective_material_tst);
	MU_RUN_TEST(reflective_material_shade_hit_tst);
	// MU_RUN_TEST(mutually_reflective_surfaces_tst);
	MU_RUN_TEST(reflection_recursive_depth_tst);
}

int main(int argc, char *argv[]) {
	MU_RUN_SUITE(reflection_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
