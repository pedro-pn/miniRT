#include "../test.h"

t_c3d			result;
t_patt			pattern;
t_material		m;
t_v3d			eye;
t_v3d			normal;
t_lgt_param		params;

void test_setup(void) {
}

void test_teardown(void) {
	/* Nothing */
}

MU_TEST(black_white_tst) {
	result = black();
	mu_assert_tuple_eq(tcolor(0, 0, 0), result);

	result = white();
	mu_assert_tuple_eq(tcolor(1, 1, 1), result);
}

MU_TEST(stripe_pattern_tst){
	pattern = stripe_pattern(black(), white());

	mu_assert_tuple_eq(tcolor(0, 0, 0), pattern.a);
	mu_assert_tuple_eq(tcolor(1, 1, 1), pattern.b);
}

MU_TEST(stripe_y_constant_tst){
	pattern = stripe_pattern(white(), black());

	result = stripe_at(pattern, point(0, 0, 0));
	mu_assert_tuple_eq(white(), result);

	result = stripe_at(pattern, point(0, 1, 0));
	mu_assert_tuple_eq(white(), result);

	result = stripe_at(pattern, point(0, 2, 0));
	mu_assert_tuple_eq(white(), result);
}

MU_TEST(stripe_z_constant_tst){
	pattern = stripe_pattern(white(), black());

	result = stripe_at(pattern, point(0, 0, 0));
	mu_assert_tuple_eq(white(), result);

	result = stripe_at(pattern, point(0, 0, 1));
	mu_assert_tuple_eq(white(), result);

	result = stripe_at(pattern, point(0, 0, 2));
	mu_assert_tuple_eq(white(), result);
}

MU_TEST(patt_alt_x_tst){
	pattern = stripe_pattern(white(), black());

	result = stripe_at(pattern, point(0, 0, 0));
	mu_assert_tuple_eq(white(), result);

	result = stripe_at(pattern, point(0.9, 0, 0));
	mu_assert_tuple_eq(white(), result);

	result = stripe_at(pattern, point(1, 0, 0));
	mu_assert_tuple_eq(black(), result);

	result = stripe_at(pattern, point(-0.1, 0, 0));
	mu_assert_tuple_eq(black(), result);

	result = stripe_at(pattern, point(-1, 0, 0));
	mu_assert_tuple_eq(black(), result);

	result = stripe_at(pattern, point(-1.1, 0, 0));
	mu_assert_tuple_eq(white(), result);
}

MU_TEST(lighting_patt_tst){
	m.pattern = stripe_pattern(white(), black());
	m.ambient = 1;
	m.diffuse = 0;
	m.specular = 0;
	params.eyev = vector(0, 0, -1);
	params.normalv = vector(0, 0, -1);
	params.position = point(0.9, 0, 0);
	point_light(point(0, 0, -10), white());

	result = lighting(m, *light(), params);
	mu_assert_tuple_eq(white(), result);

	params.position = point(1.1, 0, 0);
	result = lighting(m, *light(), params);
	mu_assert_tuple_eq(black(), result);
}

MU_TEST_SUITE(color_suite) {
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(black_white_tst);
	MU_RUN_TEST(stripe_pattern_tst);
	MU_RUN_TEST(stripe_y_constant_tst);
	MU_RUN_TEST(stripe_z_constant_tst);
	MU_RUN_TEST(patt_alt_x_tst);

	MU_RUN_TEST(lighting_patt_tst);

}

int main(int argc, char *argv[]) {
	MU_RUN_SUITE(color_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}

