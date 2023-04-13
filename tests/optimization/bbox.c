#include "../test.h"

t_box		box;
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

MU_TEST_SUITE(bounding_box_suite) {
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(empty_bounding_box_tst);
	MU_RUN_TEST(creating_bbox_with_volume);
	MU_RUN_TEST(adding_points_to_bounding_box);
	MU_RUN_TEST(sphere_bounding_box_tst);
	MU_RUN_TEST(plane_bounding_box_tst);
	MU_RUN_TEST(cube_bounding_box_tst);
}

int main(int argc, char *argv[]) {
	MU_RUN_SUITE(bounding_box_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
