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
t_intx		i;
t_v3d		_n;
t_comp		comps;

void test_setup(void) {
	p1 = point(0, 1, 0);
	p2 = point(-1, 0, 0);
	p3 = point(1, 0, 0);
	n1 = vector(0, 1, 0);
	n2 = vector(-1, 0, 0);
	n3 = vector(1, 0, 0);
	t = smooth_triangle((t_tri_p){p1, p2, p3}, (t_tri_n){n1, n2, n3});
}

void test_teardown(void) {
	/* Nothing */
	free(t);
}

MU_TEST(creating_smooth_triangle_tst) {
	assert_tuple_eq(p1, t->p.p1);
	assert_tuple_eq(p2, t->p.p2);
	assert_tuple_eq(p3, t->p.p3);
	assert_tuple_eq(n1, t->n.n1);
	assert_tuple_eq(n2, t->n.n2);
	assert_tuple_eq(n3, t->n.n3);
}

MU_TEST(intersection_with_uv_tst) {
	r = ray(point(-0.2, 0.3, -2), vector(0, 0, 1));
	xs = t->intersect(t, r);

	inter = xs.intersections->content;
	mu_assert_double_eq(0.45, inter->u);
	mu_assert_double_eq(0.25, inter->v);

	ft_lstclear(&xs.intersections, free);
}

MU_TEST(smooth_triangle_uses_uv_to_interpolate_normal_tst) {
	i = (t_intx){1, 0.45, 0.25, t};
	_n = normal_at(*t, point(0, 0, 0), i);

	assert_tuple_eq(vector(-0.5547, 0.83205, 0), _n);
}

MU_TEST(preparing_normal_in_a_smooth_triangle_tst) {
	inter = malloc(sizeof(t_intx));
	*inter = (t_intx){1, 0.45, 0.25, t};
	r = ray(point(-0.2, 0.3, -2), vector(0, 0, 1));
	xs.count = 1;
	ft_lstadd_back(&xs.intersections, ft_lstnew(inter));
	comps = prepare_computations(inter, r, xs);

	assert_tuple_eq(vector(-0.5547, 0.83205, 0), comps.normalv);

	ft_lstclear(&xs.intersections, free);
}

MU_TEST_SUITE(smooth_triangle_suite) {
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(creating_smooth_triangle_tst);
	MU_RUN_TEST(intersection_with_uv_tst);
	MU_RUN_TEST(smooth_triangle_uses_uv_to_interpolate_normal_tst);
	MU_RUN_TEST(preparing_normal_in_a_smooth_triangle_tst);
}

int main(int argc, char *argv[]) {
	MU_RUN_SUITE(smooth_triangle_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
