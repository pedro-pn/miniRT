#include "../test.h"

t_parser	parser;
int			file;
t_group		*g;
t_group		*subg;
t_group		*g2;
t_object	*t;

void test_setup(void) {
}

void test_teardown(void) {
	/* Nothing */
	ft_clean_gnl(file);

}

MU_TEST(ignoring_unrecognized_lines_tst) {
	file = open("./tests/parser/gibberish.obj", O_RDONLY);
	parser = parser_obj_file(file);

	mu_check(parser.vertices == NULL);
	close(file);
}

MU_TEST(vertex_records_tst) {
	file = open("./tests/parser/vertex.obj", O_RDONLY);
	parser = parser_obj_file(file);

	assert_tuple_eq(point(-1, 1, 0), parser.vertices[0]);
	assert_tuple_eq(point(-1, 0.5, 0), parser.vertices[1]);
	assert_tuple_eq(point(1, 0, 0), parser.vertices[2]);
	assert_tuple_eq(point(1, 1, 0), parser.vertices[3]);
	close(file);
	free(parser.vertices);
}

MU_TEST(parsing_simple_triangle_tst) {
	file = open("./tests/parser/simple_triangle.obj", O_RDONLY);
	parser = parser_obj_file(file);

	g = default_group(parser);

	t = g->group->content;
	assert_tuple_eq(parser.vertices[0], t->p.p1);
	assert_tuple_eq(parser.vertices[1], t->p.p2);
	assert_tuple_eq(parser.vertices[2], t->p.p3);

	t = g->group->next->content;
	assert_tuple_eq(parser.vertices[0], t->p.p1);
	assert_tuple_eq(parser.vertices[2], t->p.p2);
	assert_tuple_eq(parser.vertices[3], t->p.p3);

	free_group(g);
	clean_parser(&parser);
	close(file);
}

MU_TEST(triangulating_polygons_tst) {
	file = open("./tests/parser/polygon.obj", O_RDONLY);
	parser = parser_obj_file(file);

	g = default_group(parser);

	t = g->group->content;
	assert_tuple_eq(parser.vertices[0], t->p.p1);
	assert_tuple_eq(parser.vertices[1], t->p.p2);
	assert_tuple_eq(parser.vertices[2], t->p.p3);

	t = g->group->next->content;
	assert_tuple_eq(parser.vertices[0], t->p.p1);
	assert_tuple_eq(parser.vertices[2], t->p.p2);
	assert_tuple_eq(parser.vertices[3], t->p.p3);

	t = g->group->next->next->content;
	assert_tuple_eq(parser.vertices[0], t->p.p1);
	assert_tuple_eq(parser.vertices[3], t->p.p2);
	assert_tuple_eq(parser.vertices[4], t->p.p3);

	free_group(g);
	clean_parser(&parser);
	close(file);
}

MU_TEST(triangles_in_groups_tst) {
	file = open("./tests/parser/groups.obj", O_RDONLY);
	parser = parser_obj_file(file);

	g = obj_to_group(parser);

	subg = g->group->content;
	t = subg->group->content;
	assert_tuple_eq(parser.vertices[0], t->p.p1);
	assert_tuple_eq(parser.vertices[1], t->p.p2);
	assert_tuple_eq(parser.vertices[2], t->p.p3);

	subg = g->group->next->content;
	t = subg->group->content;
	assert_tuple_eq(parser.vertices[0], t->p.p1);
	assert_tuple_eq(parser.vertices[2], t->p.p2);
	assert_tuple_eq(parser.vertices[3], t->p.p3);

	clean_parser(&parser);
	free_group(g);
	close(file);
}

MU_TEST(vextex_normal_records_tst) {
	file = open("./tests/parser/vertex_records.obj", O_RDONLY);
	parser = parser_obj_file(file);

	assert_tuple_eq(vector(0, 0, 1), parser.normals[0]);
	assert_tuple_eq(vector(0.707, 0, -0.707), parser.normals[1]);
	assert_tuple_eq(vector(1, 2, 3), parser.normals[2]);

	clean_parser(&parser);
	close(file);
}

MU_TEST(faces_with_normal_tst) {
	file = open("./tests/parser/faces_normal.obj", O_RDONLY);
	parser = parser_obj_file(file);

	g = default_group(parser);


	t = g->group->content;
	assert_tuple_eq(parser.vertices[0], t->p.p1);
	assert_tuple_eq(parser.vertices[1], t->p.p2);
	assert_tuple_eq(parser.vertices[2], t->p.p3);
	assert_tuple_eq(parser.normals[2], t->n.n1);
	assert_tuple_eq(parser.normals[0], t->n.n2);
	assert_tuple_eq(parser.normals[1], t->n.n3);

	t = g->group->next->content;
	assert_tuple_eq(parser.vertices[0], t->p.p1);
	assert_tuple_eq(parser.vertices[1], t->p.p2);
	assert_tuple_eq(parser.vertices[2], t->p.p3);
	assert_tuple_eq(parser.normals[2], t->n.n1);
	assert_tuple_eq(parser.normals[0], t->n.n2);
	assert_tuple_eq(parser.normals[1], t->n.n3);

	clean_parser(&parser);
	free_group(g);
	close(file);
}

MU_TEST_SUITE(wavefront_suite) {
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(ignoring_unrecognized_lines_tst);
	MU_RUN_TEST(vertex_records_tst);
	MU_RUN_TEST(parsing_simple_triangle_tst);
	MU_RUN_TEST(triangulating_polygons_tst);
	MU_RUN_TEST(triangles_in_groups_tst);
	MU_RUN_TEST(vextex_normal_records_tst);
	MU_RUN_TEST(faces_with_normal_tst);
}

int main(int argc, char *argv[]) {
	MU_RUN_SUITE(wavefront_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
