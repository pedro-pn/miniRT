#include "../test.h"

t_c3d			result;
t_patt			_pattern;
t_material		m;
t_v3d			eye;
t_v3d			normal;
t_lgt_param		params;
t_matrix		mx;
t_object		*obj;

void test_setup(void) {
	obj = sphere();
	obj->material.ambient = 1;
	obj->material.diffuse = 0;
	obj->material.shininess = 0;
	obj->material.specular = 0;
}

void test_teardown(void) {
	/* Nothing */
	free(obj);
}

MU_TEST(black_white_tst) {
	result = black();
	assert_tuple_eq(tcolor(0, 0, 0), result);

	result = white();
	assert_tuple_eq(tcolor(1, 1, 1), result);
}

MU_TEST(stripe_pattern_tst){
	_pattern = stripe_pattern(black(), white());

	assert_tuple_eq(tcolor(0, 0, 0), _pattern.a);
	assert_tuple_eq(tcolor(1, 1, 1), _pattern.b);
}

MU_TEST(stripe_y_constant_tst){
	_pattern = stripe_pattern(white(), black());

	result = stripe_at(_pattern, point(0, 0, 0));
	assert_tuple_eq(white(), result);

	result = stripe_at(_pattern, point(0, 1, 0));
	assert_tuple_eq(white(), result);

	result = stripe_at(_pattern, point(0, 2, 0));
	assert_tuple_eq(white(), result);
}

MU_TEST(stripe_z_constant_tst){
	_pattern = stripe_pattern(white(), black());

	result = stripe_at(_pattern, point(0, 0, 0));
	assert_tuple_eq(white(), result);

	result = stripe_at(_pattern, point(0, 0, 1));
	assert_tuple_eq(white(), result);

	result = stripe_at(_pattern, point(0, 0, 2));
	assert_tuple_eq(white(), result);
}

MU_TEST(patt_alt_x_tst){
	_pattern = stripe_pattern(white(), black());

	result = stripe_at(_pattern, point(0, 0, 0));
	assert_tuple_eq(white(), result);

	result = stripe_at(_pattern, point(0.9, 0, 0));
	assert_tuple_eq(white(), result);

	result = stripe_at(_pattern, point(1, 0, 0));
	assert_tuple_eq(black(), result);

	result = stripe_at(_pattern, point(-0.1, 0, 0));
	assert_tuple_eq(black(), result);

	result = stripe_at(_pattern, point(-1, 0, 0));
	assert_tuple_eq(black(), result);

	result = stripe_at(_pattern, point(-1.1, 0, 0));
	assert_tuple_eq(white(), result);
}

MU_TEST(lighting_patt_tst){
	obj->pattern = stripe_pattern(white(), black());
	obj->material.ambient = 1;
	obj->material.diffuse = 0;
	obj->material.specular = 0;
	params.eyev = vector(0, 0, -1);
	params.normalv = vector(0, 0, -1);
	params.position = point(0.9, 0, 0);
	point_light(point(0, 0, -10), white());

	result = lighting(*obj, *light(), params);
	assert_tuple_eq(white(), result);

	params.position = point(1.1, 0, 0);
	result = lighting(*obj, *light(), params);
	assert_tuple_eq(black(), result);
}

MU_TEST(obj_transformation_tst){
	scaling(vector(2, 2, 2), &obj->transform);
	obj->pattern = stripe_pattern(white(), black());
	result = pattern_at(*obj, point(1.5, 0, 0));

	assert_tuple_eq(white(), result);
}

MU_TEST(stripe_transformation_tst){
	obj->pattern = stripe_pattern(white(), black());
	scaling(vector(2, 2, 2), &obj->pattern.transform);
	result = pattern_at(*obj, point(1.5, 0, 0));

	assert_tuple_eq(white(), result);
}

MU_TEST(stripe_obj_transformation_tst){
	obj->pattern = stripe_pattern(white(), black());
	scaling(vector(2, 2, 2), &obj->transform);
	translation(vector(0.5, 0, 0), &obj->pattern.transform);
	result = pattern_at(*obj, point(2.5, 0, 0));

	assert_tuple_eq(white(), result);
}

MU_TEST_SUITE(stripe_suite) {
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(black_white_tst);

	MU_RUN_TEST(stripe_pattern_tst);
	MU_RUN_TEST(stripe_y_constant_tst);
	MU_RUN_TEST(stripe_z_constant_tst);
	MU_RUN_TEST(patt_alt_x_tst);

	MU_RUN_TEST(lighting_patt_tst);

	MU_RUN_TEST(obj_transformation_tst);
	MU_RUN_TEST(stripe_transformation_tst);
	MU_RUN_TEST(stripe_obj_transformation_tst);

}

int main(int argc, char *argv[]) {
	MU_RUN_SUITE(stripe_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
