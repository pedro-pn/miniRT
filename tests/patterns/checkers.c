#include "../test.h"

t_c3d			result;
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

MU_TEST(checker_x_tst) {
	obj->pattern = checkers_pattern(white(), black());

	result = pattern_at(*obj, point(0, 0, 0));
	assert_tuple_eq(white(), result);

	result = pattern_at(*obj, point(0.99, 0, 0));
	assert_tuple_eq(white(), result);

	result = pattern_at(*obj, point(1.01, 0, 0));
	assert_tuple_eq(black(), result);
}

MU_TEST(checker_y_tst) {
	obj->pattern = checkers_pattern(white(), black());

	result = pattern_at(*obj, point(0, 0, 0));
	assert_tuple_eq(white(), result);

	result = pattern_at(*obj, point(0, 0.99, 0));
	assert_tuple_eq(white(), result);

	result = pattern_at(*obj, point(0, 1.01, 0));
	assert_tuple_eq(black(), result);
}

MU_TEST(checker_z_tst) {
	obj->pattern = checkers_pattern(white(), black());

	result = pattern_at(*obj, point(0, 0, 0));
	assert_tuple_eq(white(), result);

	result = pattern_at(*obj, point(0, 0, 0.99));
	assert_tuple_eq(white(), result);

	result = pattern_at(*obj, point(0, 0, 1.01));
	assert_tuple_eq(black(), result);
}

MU_TEST_SUITE(checker_suite) {
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(checker_x_tst);
	MU_RUN_TEST(checker_y_tst);
	MU_RUN_TEST(checker_z_tst);

}

int main(int argc, char *argv[]) {
	MU_RUN_SUITE(checker_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
