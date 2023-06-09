#include "../test.h"

t_object	*t;
t_p3d		p1;
t_p3d		p2;
t_p3d		p3;
t_v3d		v;
t_v3d		n;


void test_setup(void) {
}

void test_teardown(void) {
	/* Nothing */
}

MU_TEST(creating_triangle_tst) {
	p1 = point(0, 1, 0);
	p2 = point(-1, 0, 0);
	p3 = point(1, 0, 0);
	t = triangle(p1, p2, p3);

	assert_tuple_eq(p1, t->p1);
	assert_tuple_eq(p2, t->p2);
	assert_tuple_eq(p3, t->p3);
	assert_tuple_eq(vector(-1, -1, 0), t->e1);
	assert_tuple_eq(vector(1, -1, 0), t->e2);
	assert_tuple_eq(vector(0, 0, -1), t->normalv);
	free(t);
}


MU_TEST_SUITE(triangle_suite) {
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(creating_triangle_tst);

}

int main(int argc, char *argv[]) {
	MU_RUN_SUITE(triangle_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
