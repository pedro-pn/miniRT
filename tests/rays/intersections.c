#include "../test.h"

t_ray		_ray;
t_p3d		_position;
t_object	*_sphere;
t_intxs		xs;
t_intx		*inter;
double		t;

void test_setup(void) {
}

void test_teardown(void) {
	free(_sphere);
	ft_lstclear(&xs.intersections, free);
}

MU_TEST(sphere_inter_tst)
{
	_ray = ray(point(0, 0, -5), vector(0, 0, 1));
	_sphere = sphere();
	xs = _sphere->intersect(_sphere, _ray);

	mu_assert_int_eq(2, xs.count);

	inter = xs.intersections->content;
	mu_assert_double_eq(4.0, inter->t);

	inter = xs.intersections->next->content;
	mu_assert_double_eq(6.0, inter->t);
}

MU_TEST(sphere_tan_inter_tst){
	_ray = ray(point(0, 1, -5), vector (0, 0, 1));
	_sphere = sphere();
	xs = _sphere->intersect(_sphere, _ray);

	mu_assert_int_eq(2, xs.count);
	
	inter = xs.intersections->content;
	mu_assert_double_eq(5.0, inter->t);

	inter = xs.intersections->next->content;
	mu_assert_double_eq(5.0, inter->t);
}

MU_TEST(ray_miss_sphere_tst){
	_ray = ray(point(0, 2, -5), vector(0, 0, 1));
	_sphere = sphere();
	xs = _sphere->intersect(_sphere, _ray);

	mu_assert_int_eq(0, xs.count);
}


MU_TEST(ray_sphere_center_tst){
	_ray = ray(point(0, 0, 0), vector(0, 0, 1));
	_sphere = sphere();
	xs = _sphere->intersect(_sphere, _ray);

	mu_assert_int_eq(2, xs.count);

	inter = (t_intx *) xs.intersections->content;
	mu_assert_double_eq(-1.0, inter->t);

	inter = xs.intersections->next->content;
	mu_assert_double_eq(1.0, inter->t);
}

MU_TEST(sphere_behind_ray_tst){
	_ray = ray(point(0, 0, 5), vector(0, 0, 1));
	_sphere = sphere();
	xs = _sphere->intersect(_sphere, _ray);

	mu_assert_int_eq(2, xs.count);

	inter = xs.intersections->content;
	mu_assert_double_eq(-6.0, inter->t);

	inter = xs.intersections->next->content;
	mu_assert_double_eq(-4.0, inter->t);
}
MU_TEST(hit_all_positive_tst){
	_sphere = sphere();
	create_intersection(&xs, 2, _sphere);
	create_intersection(&xs, 1, _sphere);

	inter = hit(xs);
	mu_check(inter == xs.intersections->next->content);
}
MU_TEST(hit_some_negative_tst){
	_sphere = sphere();
	create_intersection(&xs, -1, _sphere);
	create_intersection(&xs, 1, _sphere);

	inter = hit(xs);
	mu_check(inter == xs.intersections->next->content);
}

MU_TEST(hit_all_negative_tst){
	_sphere = sphere();
	create_intersection(&xs, -2, _sphere);
	create_intersection(&xs, -1, _sphere);

	inter = hit(xs);
	mu_check(inter == NULL);
}
MU_TEST(hit_all_kind_tst){
	_sphere = sphere();
	create_intersection(&xs, 5, _sphere);
	create_intersection(&xs, 7, _sphere);
	create_intersection(&xs, -3, _sphere);
	create_intersection(&xs, 2, _sphere);

	inter = hit(xs);
	mu_check(inter == xs.intersections->next->next->next->content);
}

MU_TEST_SUITE(ray_suite) {
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(sphere_inter_tst);
	MU_RUN_TEST(sphere_tan_inter_tst);
	MU_RUN_TEST(ray_miss_sphere_tst);
	MU_RUN_TEST(ray_sphere_center_tst);
	MU_RUN_TEST(sphere_behind_ray_tst);
	MU_RUN_TEST(hit_all_positive_tst);
	MU_RUN_TEST(hit_some_negative_tst);
	MU_RUN_TEST(hit_all_negative_tst);
	MU_RUN_TEST(hit_all_kind_tst);
}

int main(int argc, char *argv[]) {
	MU_RUN_SUITE(ray_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
