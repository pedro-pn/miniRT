#include "../test.h"

t_ray		_ray;
t_p3d		_position;
t_object	*_sphere;
t_intxs		xs;
t_intx		*inter;

void test_setup(void) {
}

void test_teardown(void) {
	free(_sphere);
	ft_lstclear(&xs.intersections, free);
}

MU_TEST(ray_tst){
	_ray = ray(point(1, 2, 3), vector(4, 5, 6));
	
	mu_assert_tuple_eq(point(1, 2, 3), _ray.origin);
	mu_assert_tuple_eq(vector(4, 5, 6), _ray.direction);
}

MU_TEST(ray_t_tst){
	_ray = ray(point(2, 3, 4), vector(1, 0, 0));
	
	_position = position(0, _ray);
	mu_assert_tuple_eq(point(2, 3, 4), _position);

	_position = position(1, _ray);
	mu_assert_tuple_eq(point(3, 3, 4), _position);

	_position = position(-1, _ray);
	mu_assert_tuple_eq(point(1, 3, 4), _position);

	_position = position(2.5, _ray);
	mu_assert_tuple_eq(point(4.5, 3, 4), _position);
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

MU_TEST_SUITE(ray_suite) {
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(ray_tst);
	MU_RUN_TEST(ray_t_tst);
	MU_RUN_TEST(sphere_inter_tst);
	MU_RUN_TEST(sphere_tan_inter_tst);
	MU_RUN_TEST(ray_miss_sphere_tst);
	MU_RUN_TEST(ray_sphere_center_tst);
	MU_RUN_TEST(sphere_behind_ray_tst);
}

int main(int argc, char *argv[]) {
	MU_RUN_SUITE(ray_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
