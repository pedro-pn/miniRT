#include "../test.h"

t_world		*_world;
t_object	*_object;
t_list		*_objects;
t_object	*_sphere;
t_light		expected_light;
t_matrix	expected_scal;
t_ray		_ray;
t_intxs		xs;
t_intx		*inter;
t_list		*intersections;
t_list		*node;
t_comp		comps;

void test_setup(void) {
	point_light(point(-10, 10, -10), tcolor(1, 1, 1));
	world()->objects = NULL;
	_sphere = sphere();
}

void test_teardown(void) {
	/* Nothing */
	ft_lstclear(&world()->objects, free);
	free(_sphere);
}

MU_TEST(world_tst) {
	_world = world();

	mu_check(_world->objects == NULL);
}

MU_TEST(sort_tst){
	ft_lstadd_back(&intersections, ft_lstnew(new_intersection(9.0, NULL)));
	ft_lstadd_back(&intersections, ft_lstnew(new_intersection(2.0, NULL)));
	ft_lstadd_back(&intersections, ft_lstnew(new_intersection(4.0, NULL)));
	ft_lstadd_back(&intersections, ft_lstnew(new_intersection(1.0, NULL)));
	ft_lstadd_back(&intersections, ft_lstnew(new_intersection(2.0, NULL)));
	ft_lstadd_back(&intersections, ft_lstnew(new_intersection(454.0, NULL)));
	ft_lstadd_back(&intersections, ft_lstnew(new_intersection(3.0, NULL)));
	ft_lstadd_back(&intersections, ft_lstnew(new_intersection(-2.0, NULL)));
	ft_lstadd_back(&intersections, ft_lstnew(new_intersection(3.4, NULL)));

	node = intersections;
	sort_intersections(intersections);
	while (node)
	{
		printf("%f\n", ((t_intx *)node->content)->t);
		node = node->next;
	}
	mu_assert_double_eq(-2.0, ((t_intx *)intersections->content)->t);
	ft_lstclear(&intersections, free);
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

MU_TEST(intersect_world_tst){
	default_world();
	_ray = ray(point(0, 0, -5), vector(0, 0, 1));
	xs = intersect_world(_ray);
	node = xs.intersections;

	mu_assert_int_eq(4.0, xs.count);

	inter = node->content;
	mu_assert_double_eq(4.0, inter->t);

	node = node->next;
	inter = node->content;
	mu_assert_double_eq(4.5, inter->t);

	node = node->next;
	inter = node->content;
	mu_assert_double_eq(5.5, inter->t);

	node = node->next;
	inter = node->content;
	mu_assert_double_eq(6.0, inter->t);
	ft_lstclear(&xs.intersections, free);
}

MU_TEST(precomputing_state_tst){
	_ray = ray(point(0, 0, -5), vector(0, 0,  1));
	*inter = (t_intx){4.0, _sphere};
	comps = prepare_computations(*inter, _ray);
	
	mu_check(_sphere == comps.object);
	mu_assert_double_eq(inter->t, comps.t);
	mu_assert_tuple_eq(point(0, 0, -1), comps.point);
	mu_assert_tuple_eq(vector(0, 0, -1), comps.eyev);
	mu_assert_tuple_eq(vector(0, 0, -1), comps.normalv);
}

MU_TEST(hit_outside_tst){
	_ray = ray(point(0, 0, -5), vector(0, 0, 1));
	*inter = (t_intx){4, _sphere};
	comps = prepare_computations(*inter, _ray);

	mu_check(comps.inside == false);
}

MU_TEST(hit_inside_tst){
	_ray = ray(point(0, 0, 0), vector(0, 0, 1));
	*inter = (t_intx){1, _sphere};
	comps = prepare_computations(*inter, _ray);

	mu_check(comps.inside == true);
	mu_assert_tuple_eq(point(0, 0, 1), comps.point);
	mu_assert_tuple_eq(vector(0, 0, -1), comps.eyev);
	mu_assert_tuple_eq(vector(0, 0, -1), comps.normalv);
}

MU_TEST_SUITE(world_suite) {
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(world_tst);
	MU_RUN_TEST(default_word);
	MU_RUN_TEST(sort_tst);
	MU_RUN_TEST(intersect_world_tst);
	MU_RUN_TEST(precomputing_state_tst);
	MU_RUN_TEST(hit_outside_tst);
	MU_RUN_TEST(hit_inside_tst);
}

int main(int argc, char *argv[]) {
	MU_RUN_SUITE(world_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}

