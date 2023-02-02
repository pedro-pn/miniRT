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
}

void test_teardown(void) {
	/* Nothing */
	ft_lstclear(&world()->objects, free);
}

// Scenario: Reflectivity for the default material
// Given m ← material()
// Then m.reflective = 0.0

MU_TEST(reflection_tst) {
	mat = material();

	mu_assert_double_eq(0.0,  mat.reflective);
}



// Scenario: Precomputing the reflection vector
// Given shape ← plane()
// And r ← ray(point(0, 1, -1), vector(0, -√2/2, √2/2))
// And i ← intersection(√2, shape)
// When comps ← prepare_computations(i, r)
// Then comps.reflectv = vector(0, √2/2, √2/2)

MU_TEST(reflection_vector_tst){
	obj = plane();
	r = ray(point(0, 1, -1), vector(0, -sqrt(2)/2, sqrt(2)/2));
	inter = (t_intx){sqrt(2), obj};
	comps = prepare_computations(inter, r);
	free(obj);

	mu_assert_tuple_eq(vector(0, sqrt(2) / 2, sqrt(2) / 2), comps.reflectv);

}

// Scenario: The reflected color for a nonreflective material
// Given w ← default_world()
// And r ← ray(point(0, 0, 0), vector(0, 0, 1))
// And shape ← the second object in w
// And shape.material.ambient ← 1
// And i ← intersection(1, shape)
// When comps ← prepare_computations(i, r)
// And color ← reflected_color(w, comps)
// Then color = color(0, 0, 0)

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

// Scenario: The reflected color for a reflective material
// Given w ← default_world()
// And shape ← plane() with:
// | material.reflective | 0.5
// || transform
// | translation(0, -1, 0) |
// And shape is added to w
// And r ← ray(point(0, 0, -3), vector(0, -√2/2, √2/2))
// And i ← intersection(√2, shape)
// When comps ← prepare_computations(i, r)
// And color ← reflected_color(w, comps)
// Then color = color(0.19032, 0.2379, 0.14274)

MU_TEST(reflective_material_tst){
	obj = plane();
	obj->material.reflective = 0.5;
	translation(vector(0, -1, 0), &obj->transform);
	create_object(obj);
	r = ray(point(0, 0, -3), vector(0, -sqrt(2) / 2, sqrt(2) / 2));
	inter = (t_intx){sqrt(2), obj};
	comps = prepare_computations(inter, r);
	result_color = reflected_color(comps);

	mu_check((t_object *)world()->objects->next->next->content == obj);
	mu_assert_tuple_eq(tcolor(0.19032, 0.2379, 0.14274), result_color);
}


MU_TEST_SUITE(reflection_suite) {
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(reflection_tst);
	MU_RUN_TEST(reflection_vector_tst);
	MU_RUN_TEST(nonreflective_material_tst);
	MU_RUN_TEST(reflective_material_tst);
}

int main(int argc, char *argv[]) {
	MU_RUN_SUITE(reflection_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
