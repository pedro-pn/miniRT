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

MU_TEST(gradient_tst) {
	obj->pattern = gradient_pattern(white(), black());

	result = pattern_at_object(*obj, point(0, 0, 0));
	mu_assert_tuple_eq(white(), result);

	result = pattern_at_object(*obj, point(0.25, 0, 0));
	mu_assert_tuple_eq(tcolor(0.75, 0.75, 0.75), result);

	result = pattern_at_object(*obj, point(0.5, 0, 0));
	mu_assert_tuple_eq(tcolor(0.5, 0.5, 0.5), result);

	result = pattern_at_object(*obj, point(0.75, 0, 0));
	mu_assert_tuple_eq(tcolor(0.25, 0.25, 0.25), result);
}


MU_TEST_SUITE(gradient_suite) {
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(gradient_tst);

}

int main(int argc, char *argv[]) {
	MU_RUN_SUITE(gradient_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
