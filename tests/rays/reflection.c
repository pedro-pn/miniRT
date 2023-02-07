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

void test_setup(void) {
}

void test_teardown(void) {
	/* Nothing */
}

MU_TEST(reflection_45_tst) {
	vec_result = reflect(vector(1, -1, 0), vector(0, 1, 0));

	assert_tuple_eq(vector(1, 1, 0), vec_result);
}

MU_TEST(reflection_slanted_tst) {
	vec_result = reflect(vector(0, -1, 0), vector(sqrt(2) / 2, sqrt(2) / 2, 0));

	assert_tuple_eq(vector(1, 0, 0), vec_result);
}

MU_TEST_SUITE(reflection_suite) {
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(reflection_45_tst);
	MU_RUN_TEST(reflection_slanted_tst);
}

int main(int argc, char *argv[]) {
	MU_RUN_SUITE(reflection_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
