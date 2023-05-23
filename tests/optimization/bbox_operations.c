#include "../test.h"

t_box		box;
t_box		box_2;
t_box		b1;
t_p3d		p1;
t_p3d		p2;
t_object	*obj;
t_object	*s;
t_object	*cy;
t_matrix	rot_x;
t_matrix	trans;
t_matrix	scal;
t_matrix	rot_y;
t_matrix	mx;
t_group		*g;
t_ray		r;

void test_setup(void) {
}

void test_teardown(void) {
	/* Nothing */
}

MU_TEST(transforming_bounding_box) {
	box = bounding_box(point(-1, -1, -1), point(1, 1, 1));
	rotation_x(MY_PI / 4, &rot_x);
	rotation_y(MY_PI / 4, &rot_y);
	mx_product(rot_x, rot_y, &mx);
	box_2 = transform_bbox(box, mx);

	assert_tuple_eq(point(-1.4142, -1.7071, -1.7071), box_2.min);
	assert_tuple_eq(point(1.4142, 1.7071, 1.7071), box_2.max);
}

MU_TEST(querying_shapes_bbox_in_its_parents_space) {
	obj = sphere();
	translation(vector(1, -3, 5), &trans);
	scaling(vector(0.5, 2, 4), &scal);
	mx_product(trans, scal, &obj->transform);
	box = parent_space_bounds_of(*obj);

	assert_tuple_eq(point(0.5, -5, 1), box.min);
	assert_tuple_eq(point(1.5, -1, 9), box.max);
	free(obj);
}

MU_TEST(groups_bounding_box_contains_its_children) {
	s = sphere();
	translation(vector(2, 5, -3), &trans);
	scaling(vector(2, 2, 2), &scal);
	mx_product(trans, scal, &s->transform);
	cy = cylinder();
	cy->maximum = 2;
	cy->minimum = -2;
	translation(vector(-4, -1, 4), &trans);
	scaling(vector(0.5, 1, 0.5), &scal);
	mx_product(trans, scal, &cy->transform);
	g = group();
	add_child(g, s);
	add_child(g, cy);
	box = g->bound_of(*g);

	assert_tuple_eq(point(-4.5, -3, -5), box.min);
	assert_tuple_eq(point(4, 7, 4.5), box.max);

	free_group(g);
}

void	intersect_bbox(t_box box, t_p3d origin, t_v3d direction, t_bool result) {
	r = ray(origin, normalize(direction));

	mu_check(intersect_bounding_box(box, r) == result);
}

MU_TEST(intersecting_ray_with_cubic_bounding_box) {
	box = bounding_box(point(-1, -1, -1), point(1, 1, 1));

	intersect_bbox(box, point(5, 0.5, 0), vector(-1, 0, 0), true);
	intersect_bbox(box, point(-5, 0.5, 0), vector(1, 0, 0), true);
	intersect_bbox(box, point(0.5, 5, 0), vector(0, -1, 0), true);
	intersect_bbox(box, point(0.5, -5, 0), vector(0, 1, 0), true);
	intersect_bbox(box, point(0.5, 0, 5), vector(0, 0, -1), true);
	intersect_bbox(box, point(0.5, 0, -5), vector(0, 0, 1), true);
	intersect_bbox(box, point(0, 0.5, 0), vector(0, 0, 1), true);
	intersect_bbox(box, point(-2, 0, 0), vector(2, 4, 6), false);
	intersect_bbox(box, point(0, -2, 0), vector(6, 2, 4), false);
	intersect_bbox(box, point(0, 0, -2), vector(4, 6, 2), false);
	intersect_bbox(box, point(2, 0, 2), vector(0, 0, -1), false);
	intersect_bbox(box, point(0, 2, 2), vector(0, -1, 0), false);
	intersect_bbox(box, point(2, 2, 0), vector(-1, 0, 0), false);
}

MU_TEST(intersecting_ray_with_non_cubic_bounding_box) {
	box = bounding_box(point(5, -2, 0), point(11, 4, 7));

	intersect_bbox(box, point(15, 1, 2), vector(-1, 0, 0), true);
	intersect_bbox(box, point(-5, -1, 4), vector(1, 0, 0), true);
	intersect_bbox(box, point(7, 6, 5), vector(0, -1, 0), true);
	intersect_bbox(box, point(9, -5, 6), vector(0, 1, 0), true);
	intersect_bbox(box, point(8, 2, 12), vector(0, 0, -1), true);
	intersect_bbox(box, point(6, 0, -5), vector(0, 0, 1), true);
	intersect_bbox(box, point(8, 1, 3.5), vector(0, 0, 1), true);
	intersect_bbox(box, point(9, -1, -8), vector(2, 4, 6), false);
	intersect_bbox(box, point(8, 3, -4), vector(6, 2, 4), false);
	intersect_bbox(box, point(9, -1, -2), vector(4, 6, 2), false);
	intersect_bbox(box, point(4, 0, 9) , vector(0, 0, -1), false);
	intersect_bbox(box, point(8, 6, -1), vector(0, -1, 0), false);
	intersect_bbox(box, point(12, 5, 4), vector(-1, 0, 0), false);
}

MU_TEST_SUITE(bounding_box_operations_suite) {
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(transforming_bounding_box);
	MU_RUN_TEST(querying_shapes_bbox_in_its_parents_space);
	MU_RUN_TEST(groups_bounding_box_contains_its_children);
	MU_RUN_TEST(intersecting_ray_with_cubic_bounding_box);
	MU_RUN_TEST(intersecting_ray_with_non_cubic_bounding_box);
}

int main(int argc, char *argv[]) {
	MU_RUN_SUITE(bounding_box_operations_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
