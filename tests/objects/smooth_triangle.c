#include "../test.h"

t_object	*t;
t_object	*obj;
t_p3d		p1;
t_p3d		p2;
t_p3d		p3;
t_v3d		v;
t_v3d		n1;
t_v3d		n2;
t_v3d		n3;
t_ray		r;
t_intxs		xs;
t_intx		*inter;


void test_setup(void) {
}

void test_teardown(void) {
	/* Nothing */
}

MU_TEST(creating_smooth_triangle_tst) {
	p1 = point(0, 1, 0);
	p2 = point(-1, 0, 0);
	p3 = point(1, 0, 0);
	n1 = vector(0, 1, 0);
	n2 = vector(-1, 0, 0);
	n3 = vector(1, 0, 0);

	t = smooth_triangle((t_tri_p){p1, p2, p3}, (t_tri_n){n1, n2, n3});

	assert_tuple_eq(p1, t->p.p1);
	assert_tuple_eq(p2, t->p.p2);
	assert_tuple_eq(p3, t->p.p3);
	assert_tuple_eq(n1, t->n.n1);
	assert_tuple_eq(n2, t->n.n2);
	assert_tuple_eq(n3, t->n.n3);

	free(t);
}

MU_TEST_SUITE(smooth_triangle_suite) {
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(creating_smooth_triangle_tst);
}

int main(int argc, char *argv[]) {
	MU_RUN_SUITE(smooth_triangle_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
