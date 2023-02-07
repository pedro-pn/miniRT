#include "../test.h"

t_material	_material;
t_object	*obj;
t_object	*obj_a;
t_object	*obj_b;
t_object	*obj_c;
t_matrix	scal;
t_matrix	trans;
t_matrix	mx1;
t_matrix	mx2;
t_ray		r;
t_intxs		xs;
t_intx		*inter;
t_intx		intr;
t_list		*node;
t_comp		comps;

void test_setup(void) {
	obj = NULL;
}

void test_teardown(void) {
	/* Nothing */
	free(obj);
}

MU_TEST(refractive_transp_tst) {
	_material = material();

	mu_assert_double_eq(0, _material.transparency);
	mu_assert_double_eq(1.0, _material.refractive_index);
}

MU_TEST(glass_sphere_tst){
	obj = glass_sphere();

	mu_assert_double_eq(1.0, obj->material.transparency);
	mu_assert_double_eq(1.5, obj->material.refractive_index);
}

MU_TEST(lstfind_tst)
{
	t_list *lst = NULL;
	obj_a = glass_sphere();
	obj_b = glass_sphere();
	obj_c = glass_sphere();


	ft_lstadd_back(&lst, ft_lstnew(obj_a));
	ft_lstadd_back(&lst, ft_lstnew(obj_b));
	ft_lstadd_back(&lst, ft_lstnew(obj_c));

	mu_check(ft_lstfind(lst, obj_a)->content == obj_a);
	mu_check(ft_lstfind(lst, obj_b)->content == obj_b);
	mu_check(ft_lstfind(lst, obj_c)->content == obj_c);
}

MU_TEST(lstremove_tst)
{
	t_list *lst = NULL;
	obj_a = glass_sphere();
	obj_b = glass_sphere();
	obj_c = glass_sphere();


	ft_lstadd_back(&lst, ft_lstnew(obj_a));
	ft_lstadd_back(&lst, ft_lstnew(obj_b));
	ft_lstadd_back(&lst, ft_lstnew(obj_c));

	ft_lstremove(&lst, obj_b);
	mu_check(ft_lstfind(lst, obj_a)->content == obj_a);
	mu_check(ft_lstfind(lst, obj_b) == NULL);
	mu_check(ft_lstfind(lst, obj_c)->content == obj_c);
}

MU_TEST(finding_refraction_tst){
	double	n1[6] = {1.0, 1.5, 2.0, 2.5, 2.5, 1.5};
	double	n2[6] = {1.5, 2.0, 2.5, 2.5, 1.5, 1.0};

	obj_a = glass_sphere();
	obj_a->material.refractive_index = 1.5;
	scaling(vector(2, 2, 2), &obj_a->transform);
	obj_b = glass_sphere();
	obj_b->material.refractive_index = 2.0;
	translation(vector(0, 0, -0.25), &obj_b->transform);
	obj_c = glass_sphere();
	obj_c->material.refractive_index = 2.5;
	translation(vector(0, 0, 0.25), &obj_c->transform);
	r = ray(point(0, 0, -4), vector(0, 0, 1));
	create_intersection(&xs.intersections, 2.0, obj_a);
	create_intersection(&xs.intersections, 2.75, obj_b);
	create_intersection(&xs.intersections, 3.25, obj_c);
	create_intersection(&xs.intersections, 4.75, obj_b);
	create_intersection(&xs.intersections, 5.25, obj_c);
	create_intersection(&xs.intersections, 6.0, obj_a);
	node = xs.intersections;
	for (int i = 0; i < 6; i++)
	{
		inter = node->content;
		comps = prepare_computations(inter, r, xs);
		mu_assert_double_eq(n1[i], comps.n1);
		mu_assert_double_eq(n2[i], comps.n2);
		node = node->next;
	}
}


MU_TEST_SUITE(refraction_suite) {
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(refractive_transp_tst);
	MU_RUN_TEST(glass_sphere_tst);
	MU_RUN_TEST(finding_refraction_tst);
	MU_RUN_TEST(lstfind_tst);
	MU_RUN_TEST(lstremove_tst);
}

int main(int argc, char *argv[]) {
	MU_RUN_SUITE(refraction_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
