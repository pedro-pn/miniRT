#include "../test.h"

t_c3d			result;
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

MU_TEST(ring_tst) {
	obj->pattern = ring_pattern(white(), black());
	
	result = pattern_at(*obj, point(0, 0, 0));
	mu_assert_tuple_eq(white(), result);

	result = pattern_at(*obj, point(1, 0, 0));
	mu_assert_tuple_eq(black(), result);

	result = pattern_at(*obj, point(0, 0, 1));
	mu_assert_tuple_eq(black(), result);
	
	result = pattern_at(*obj, point(0.708, 0, 0.708));
	mu_assert_tuple_eq(black(), result);
}


MU_TEST_SUITE(ring_suite) {
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(ring_tst);

}

int main(int argc, char *argv[]) {
	MU_RUN_SUITE(ring_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
