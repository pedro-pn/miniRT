#include "../test.h"

t_c3d			result;
t_material		m;
t_v3d			eye;
t_v3d			normal;
t_lgt_param		params;
t_matrix		mx;
t_object		*obj;
t_p3d			presult;

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

MU_TEST(spherical_map_tst){
	presult = spherical_map(point(0, 0, -1));
	assert_tuple_eq(point(0, 0.5, 0), presult);

	presult = spherical_map(point(1, 0, 0));
	assert_tuple_eq(point(0.25, 0.5, 0), presult);

	presult = spherical_map(point(0, 0, 1));
	assert_tuple_eq(point(0.5, 0.5, 0), presult);

	presult = spherical_map(point(-1, 0, 0));
	assert_tuple_eq(point(0.75, 0.5, 0), presult);

	presult = spherical_map(point(0, 1, 0));
	assert_tuple_eq(point(0.5, 1.0, 0), presult);

	presult = spherical_map(point(0, -1, 0));
	assert_tuple_eq(point(0.5, 0, 0), presult);

	presult = spherical_map(point(sqrt(2) / 2, sqrt(2) / 2, 0));
	assert_tuple_eq(point(0.25, 0.75, 0), presult);
}

MU_TEST_SUITE(uv_suite) {
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(spherical_map_tst);

}

int main(int argc, char *argv[]) {
	MU_RUN_SUITE(uv_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
