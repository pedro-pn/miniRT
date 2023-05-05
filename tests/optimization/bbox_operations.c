#include "../test.h"

t_box		box;
t_box		box_2;
t_box		b1;
t_p3d		p1;
t_p3d		p2;
t_object	*obj;
t_matrix	rot_x;
t_matrix	rot_y;
t_matrix	mx;

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

MU_TEST_SUITE(bounding_box_operations_suite) {
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(transforming_bounding_box);
}

int main(int argc, char *argv[]) {
	MU_RUN_SUITE(bounding_box_operations_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
