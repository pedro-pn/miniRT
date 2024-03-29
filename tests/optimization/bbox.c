#include "../test.h"

t_box		box;
t_box		box_2;
t_box		b1;
t_p3d		p1;
t_p3d		p2;
t_object	*obj;

void test_setup(void) {
}

void test_teardown(void) {
	/* Nothing */
}

MU_TEST(empty_bounding_box_tst) {
	box = empty_bounding_box();
	
	assert_tuple_eq(point(INF, INF, INF), box.min);
	assert_tuple_eq(point(-INF, -INF, -INF), box.max);
}

MU_TEST(creating_bbox_with_volume) {
	box = bounding_box(point(-1, -2, -3), point(3, 2, 1));
	
	assert_tuple_eq(point(-1, -2, -3), box.min);
	assert_tuple_eq(point(3, 2, 1), box.max);
}

MU_TEST(adding_points_to_bounding_box) {
	box = empty_bounding_box();
	p1 = point(-5, 2, 0);
	p2 = point(7, 0, -3);
	add_point(&box, p1);
	add_point(&box, p2);
	
	assert_tuple_eq(point(-5, 0, -3), box.min);
	assert_tuple_eq(point(7, 2, 0), box.max);
}

MU_TEST(sphere_bounding_box_tst) {
	obj = sphere();
	box = obj->bound_of(*obj);
	
	assert_tuple_eq(point(-1, -1, -1), box.min);
	assert_tuple_eq(point(1, 1, 1), box.max);
	free(obj);
}

MU_TEST(plane_bounding_box_tst) {
	obj = plane();
	box = obj->bound_of(*obj);
	
	assert_tuple_eq(point(-INF, 0, -INF), box.min);
	assert_tuple_eq(point(INF, 0, INF), box.max);
	free(obj);
}

MU_TEST(cube_bounding_box_tst) {
	obj = cube();
	box = obj->bound_of(*obj);
	
	assert_tuple_eq(point(-1, -1, -1), box.min);
	assert_tuple_eq(point(1, 1, 1), box.max);
	free(obj);
}

MU_TEST(unbounded_cylinder_bounding_box_tst) {
	obj = cylinder();
	box = obj->bound_of(*obj);
	
	assert_tuple_eq(point(-1, -INF, -1), box.min);
	assert_tuple_eq(point(1, INF, 1), box.max);
	free(obj);
}

MU_TEST(bounded_cylinder_bounding_box_tst) {
	obj = cylinder();
	obj->maximum = 3;
	obj->minimum = -5;
	box = obj->bound_of(*obj);
	
	assert_tuple_eq(point(-1, -5, -1), box.min);
	assert_tuple_eq(point(1, 3, 1), box.max);
	free(obj);
}

MU_TEST(unbonded_cone_bounding_box_tst) {
	obj = cone();
	box = obj->bound_of(*obj);
	
	assert_tuple_eq(point(-INF, -INF, -INF), box.min);
	assert_tuple_eq(point(INF, INF, INF), box.max);
	free(obj);
}

MU_TEST(bounded_cone_bounding_box_tst) {
	obj = cone();
	obj->maximum = 3;
	obj->minimum = -5;
	box = obj->bound_of(*obj);
	
	assert_tuple_eq(point(-5, -5, -5), box.min);
	assert_tuple_eq(point(5, 3, 5), box.max);
	free(obj);
}

MU_TEST(triangle_bounding_box_tst) {
	obj = triangle((t_tri_p){point(-3, 7, 2), point(6, 2, -4), point(2, -1, -1)});
	box = obj->bound_of(*obj);

	assert_tuple_eq(point(-3, -1, -4), box.min);
	assert_tuple_eq(point(6, 7, 2), box.max);
	free(obj);
}

MU_TEST(adding_bounding_box_to_another) {
	box = bounding_box(point(-5, -2, 0), point(7, 4, 4));
	box_2 = bounding_box(point(8, -7, -2), point(14, 2, 8));
	add_bounding_box(&box, box_2);

	assert_tuple_eq(point(-5, -7, -2), box.min);
	assert_tuple_eq(point(14, 4, 8), box.max);
}

void	check_box_contains_point(t_box box, t_p3d point, t_bool result) {
	mu_check(box_contains_point(box, point) == result);
}

MU_TEST(check_if_box_contains_a_given_point) {
	box = bounding_box(point(5, -2, 0), point(11, 4, 7));

	check_box_contains_point(box, point(5, -2, 0), true);
	check_box_contains_point(box, point(11, 4, 7), true);
	check_box_contains_point(box, point(8, 1, 3), true);
	check_box_contains_point(box, point(3, 0, 3), false);
	check_box_contains_point(box, point(8, -4, 3), false);
	check_box_contains_point(box, point(8, 1, -1), false);
	check_box_contains_point(box, point(13, 1, 3), false);
	check_box_contains_point(box, point(8, 5, 3), false);
	check_box_contains_point(box, point(8, 1, 8), false);
}

void	check_box_contains_box(t_p3d min, t_p3d max, t_bool result) {
	b1 = bounding_box(point(5, -2, 0), point(11, 4, 7));
	box = bounding_box(min, max);
	
	mu_check(box_contains_box(b1, box) == result);
}

MU_TEST(check_if_box_contains_another_box) {
	check_box_contains_box(point(5, -2, 0), point(11, 4, 7), true);
	check_box_contains_box(point(6, -1, 1), point(10, 3, 6), true);
	check_box_contains_box(point(4, -3, -1), point(10, 3, 6), false);
	check_box_contains_box(point(6, -1, 1), point(12, 5, 8), false);
}

MU_TEST_SUITE(bounding_box_suite) {
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(empty_bounding_box_tst);
	MU_RUN_TEST(creating_bbox_with_volume);
	MU_RUN_TEST(adding_points_to_bounding_box);
	MU_RUN_TEST(sphere_bounding_box_tst);
	MU_RUN_TEST(plane_bounding_box_tst);
	MU_RUN_TEST(cube_bounding_box_tst);
	MU_RUN_TEST(unbounded_cylinder_bounding_box_tst);
	MU_RUN_TEST(bounded_cylinder_bounding_box_tst);
	MU_RUN_TEST(unbonded_cone_bounding_box_tst);
	MU_RUN_TEST(bounded_cone_bounding_box_tst);
	MU_RUN_TEST(triangle_bounding_box_tst);
	MU_RUN_TEST(adding_bounding_box_to_another);
	MU_RUN_TEST(check_if_box_contains_a_given_point);
	MU_RUN_TEST(check_if_box_contains_another_box);
}

int main(int argc, char *argv[]) {
	MU_RUN_SUITE(bounding_box_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
