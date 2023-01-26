#include "../test.h"

t_bool	shadow;

void test_setup(void) {
	point_light(point(-10, 10, -10), tcolor(1, 1, 1));
}

void test_teardown(void) {
	/* Nothing */
	ft_lstclear(&world()->objects, free);
}

MU_TEST(no_shadow_tst) {
	default_world();
	shadow = is_shadowed(point(0, 10, 0));

	mu_check(shadow == false);

}

MU_TEST(obj_btw_point_light_tst){
	default_world();
	shadow = is_shadowed(point(10, -10, 10));

	mu_check(shadow == true);
}

MU_TEST(object_behind_light_tst){
	default_world();
	shadow = is_shadowed(point(-20,  20, -20));

	mu_check(shadow == false);
}

MU_TEST(object_behind_point_tst){
	default_world();
	shadow = is_shadowed(point(-2,  2, -2));

	mu_check(shadow == false);
}

MU_TEST_SUITE(shadows_suite) {
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(no_shadow_tst);
	MU_RUN_TEST(obj_btw_point_light_tst);
	MU_RUN_TEST(object_behind_light_tst);
	MU_RUN_TEST(object_behind_point_tst);
}

int main(int argc, char *argv[]) {
	MU_RUN_SUITE(shadows_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
