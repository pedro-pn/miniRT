#include "../test.h"

t_world		*_world;
t_object	*_object;
t_list		*_objects;
t_light		expected_light;
t_matrix	expected_scal;

void test_setup(void) {
	point_light(point(-10, 10, -10), tcolor(1, 1, 1));
	world()->objects = NULL;
}

void test_teardown(void) {
	/* Nothing */
	ft_lstclear(&world()->objects, free);
}

MU_TEST(world_tst) {
	_world = world();

	mu_check(_world->objects == NULL);
}

MU_TEST(default_word){
	default_world();
	_world = world();

	expected_light.color = tcolor(1, 1, 1);
	expected_light.position = point(-10, 10, -10);

	mu_assert_tuple_eq(expected_light.color, _world->light.color);
	mu_assert_tuple_eq(expected_light.position, _world->light.position);

	_objects = _world->objects;
	_object = _objects->content;

	mu_assert_tuple_eq(tcolor(0.8, 1.0, 0.6), _object->material.color);
	mu_assert_double_eq(0.7, _object->material.diffuse);
	mu_assert_double_eq(0.2, _object->material.specular);

	_object = _objects->next->content;
	scaling(vector(0.5, 0.5, 0.5), &expected_scal);
	mu_check(matrix_compare(expected_scal, _object->transform));
}

MU_TEST_SUITE(world_suite) {
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(world_tst);
	MU_RUN_TEST(default_word);

}

int main(int argc, char *argv[]) {
	MU_RUN_SUITE(world_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}

