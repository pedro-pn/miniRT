#include "../test.h"

t_object	*_plane;
t_v3d		normal;
t_ray		_ray;
t_intxs		xs;
t_intx		*inter;

void test_setup(void) {
	xs.intersections = NULL;
}

void test_teardown(void) {
	/* Nothing */
	free(_plane);
	ft_lstclear(&xs.intersections, free);
}

MU_TEST(plane_normal_tst) {
	_plane = plane();
	
	normal = plane_normal_at(*_plane, point(0, 0,  0));
	mu_assert_tuple_eq(vector(0, 1, 0), normal);

	normal = plane_normal_at(*_plane, point(10, 0,  -10));
	mu_assert_tuple_eq(vector(0, 1, 0), normal);

	normal = plane_normal_at(*_plane, point(-5, 0,  150));
	mu_assert_tuple_eq(vector(0, 1, 0), normal);
}

MU_TEST(intersect_parallel_tst){
	_plane = plane();
	_ray = ray(point(0, 10, 0), vector(0, 0, 1));
	xs = _plane->intersect(_plane, _ray);

	mu_check(xs.count == 0);
	mu_check(xs.intersections == NULL);
}

MU_TEST(intersect_coplanar_tst){
	_plane = plane();
	_ray = ray(point(0, 0, 0), vector(0, 0, 1));
	xs = _plane->intersect(_plane, _ray);

	mu_check(xs.count == 0);
	mu_check(xs.intersections == NULL);
}

MU_TEST(intersecting_above_tst){
	_plane = plane();
	_ray = ray(point(0, 1, 0), vector(0, -1, 0));
	xs = _plane->intersect(_plane, _ray);
	inter = xs.intersections->content;

	mu_assert_int_eq(1, xs.count);
	mu_check(inter->object == _plane);
}

MU_TEST(intersecting_below_tst){
	_plane = plane();
	_ray = ray(point(0, -1, 0), vector(0, 1, 0));
	xs = _plane->intersect(_plane, _ray);
	inter = xs.intersections->content;

	mu_assert_int_eq(1, xs.count);
	mu_check(inter->object == _plane);
}

MU_TEST_SUITE(plane_suite) {
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(plane_normal_tst);
	MU_RUN_TEST(intersect_parallel_tst);
	MU_RUN_TEST(intersect_coplanar_tst);
	MU_RUN_TEST(intersecting_above_tst);
	MU_RUN_TEST(intersecting_below_tst);
}

int main(int argc, char *argv[]) {
	MU_RUN_SUITE(plane_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}

