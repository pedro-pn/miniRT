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
	xs = intersect(_sphere, _ray);

	mu_assert_int_eq(2, xs.count);

	inter = xs.intersections->content;
	mu_assert_double_eq(4.0, inter->t);

	inter = xs.intersections->next->content;
	mu_assert_double_eq(6.0, inter->t);
}

MU_TEST(sphere_tan_inter_tst){
	_ray = ray(point(0, 1, -5), vector (0, 0, 1));
	_sphere = sphere();
	xs = intersect(_sphere, _ray);

	mu_assert_int_eq(2, xs.count);
	
	inter = xs.intersections->content;
	mu_assert_double_eq(5.0, inter->t);

	inter = xs.intersections->next->content;
	mu_assert_double_eq(5.0, inter->t);
}

MU_TEST(ray_miss_sphere_tst){
	_ray = ray(point(0, 2, -5), vector(0, 0, 1));
	_sphere = sphere();
	xs = intersect(_sphere, _ray);

	mu_assert_int_eq(0, xs.count);
}


MU_TEST(ray_sphere_center_tst){
	_ray = ray(point(0, 0, 0), vector(0, 0, 1));
	_sphere = sphere();
	xs = intersect(_sphere, _ray);

	mu_assert_int_eq(2, xs.count);

	inter = (t_intx *) xs.intersections->content;
	mu_assert_double_eq(-1.0, inter->t);

	inter = xs.intersections->next->content;
	mu_assert_double_eq(1.0, inter->t);
}

MU_TEST(sphere_behind_ray_tst){
	_ray = ray(point(0, 0, 5), vector(0, 0, 1));
	_sphere = sphere();
	xs = intersect(_sphere, _ray);

	mu_assert_int_eq(2, xs.count);

	inter = xs.intersections->content;
	mu_assert_double_eq(-6.0, inter->t);

	inter = xs.intersections->next->content;
	mu_assert_double_eq(-4.0, inter->t);

}

// Scenario : The hit, when all intersections have positive t
// Given s ← sphere()
// And i1 ← intersection(1, s)
// And i2 ← intersection(2, s)
// And xs ← intersections(i2, i1)
// When i ← hit(xs)
// Then i = i1

MU_TEST(hit_all_positive_tst){
	_sphere = sphere();
	create_intersection(&xs.intersections, 2, _sphere);
	create_intersection(&xs.intersections, 1, _sphere);

	inter = hit(xs);
	mu_check(inter == xs.intersections->next->content);
}


// Scenario : The hit, when some intersections have negative t
// Given s ← sphere()
// And i1 ← intersection(-1, s)
// And i2 ← intersection(1, s)
// And xs ← intersections(i2, i1)
// When i ← hit(xs)
// Then i = i2

MU_TEST(hit_some_negative_tst){
	_sphere = sphere();
	create_intersection(&xs.intersections, -1, _sphere);
	create_intersection(&xs.intersections, 1, _sphere);

	inter = hit(xs);
	mu_check(inter == xs.intersections->next->content);
}


// Scenario : The hit, when all intersections have negative t
// Given s ← sphere()
// And i1 ← intersection(-2, s)
// And i2 ← intersection(-1, s)
// And xs ← intersections(i2, i1)
// When i ← hit(xs)
// Then i is nothing

MU_TEST(hit_all_negative_tst){
	_sphere = sphere();
	create_intersection(&xs.intersections, -2, _sphere);
	create_intersection(&xs.intersections, -1, _sphere);

	inter = hit(xs);
	mu_check(inter == NULL);
}

// Scenario : The hit is always the lowest nonnegative intersection
// Given s ← sphere()
// And i1 ← intersection(5, s)
// And i2 ← intersection(7, s)
// And i3 ← intersection(-3, s)
// And i4 ← intersection(2, s)
// And xs ← intersections(i1, i2, i3, i4)
// When i ← hit(xs)
// Then i = i4

MU_TEST(hit_all_kind_tst){
	_sphere = sphere();
	create_intersection(&xs.intersections, 5, _sphere);
	create_intersection(&xs.intersections, 7, _sphere);
	create_intersection(&xs.intersections, -3, _sphere);
	create_intersection(&xs.intersections, 2, _sphere);

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
