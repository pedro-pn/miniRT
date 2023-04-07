#include "../test.h"

t_group		*g;
t_group		*g2;
t_group		*g3;
t_group		*g4;
t_group		*g5;
t_group		*g6;
t_matrix	id;
t_object	*s;
t_object	*child;
t_group		*parent;

void test_setup(void) {
	g = group();
}

void test_teardown(void) {
	/* Nothing */
	free_group(g);
}

MU_TEST(create_group_tst) {
	mx_identity(&id);

	mu_check(matrix_compare(id, g->transform) == true);
}

MU_TEST(parent_attribute_tst) {
	s = sphere();
	
	mu_check(s->parent == 0);
	free(s);
}

MU_TEST(add_child_to_group_tst) {
	s = sphere();
	add_child(g, s);
	child = g->group->content;
	parent = s->parent;
	
	mu_check(child == s);
	mu_check(parent == g);
}

MU_TEST(group_tree_free_tst) {
	g2 = group();
	g3 = group();
	g4 = group();
	g5 = group();
	g6 = group();

	add_child(g, sphere());
	add_child(g, g2);
	add_child(g2, g3);
	add_child(g3, sphere());
	add_child(g2, sphere());
	add_child(g2, g4);
	add_child(g4, sphere());
	add_child(g4, g5);
	add_child(g5, sphere());
	add_child(g5, g6);
	add_child(g6, sphere());
	add_child(g, sphere());
}

MU_TEST_SUITE(group_suite) {
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(create_group_tst);
	MU_RUN_TEST(parent_attribute_tst);
	MU_RUN_TEST(add_child_to_group_tst);
	MU_RUN_TEST(group_tree_free_tst);
}

int main(int argc, char *argv[]) {
	MU_RUN_SUITE(group_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
