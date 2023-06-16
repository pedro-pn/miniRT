#include "../test.h"

t_parser	parser;
int			file;

void test_setup(void) {
}

void test_teardown(void) {
	/* Nothing */
	ft_clean_gnl(file);
}

MU_TEST(ignoring_unrecognized_lines_tst) {
	file = open("./tests/parser/gibberish.obj", O_RDONLY);
	parser = parser_obj_file(file);

	mu_check(parser.vertexes == NULL);
	close(file);
}

MU_TEST(vertex_records_tst) {
	file = open("./tests/parser/vertex.obj", O_RDONLY);
	parser = parser_obj_file(file);

	assert_tuple_eq(vector(-1, 1, 0), parser.vertexes[0]);
	assert_tuple_eq(vector(-1, 0.5, 0), parser.vertexes[1]);
	assert_tuple_eq(vector(1, 0, 0), parser.vertexes[2]);
	assert_tuple_eq(vector(1, 1, 0), parser.vertexes[3]);
	close(file);
	free(parser.vertexes);
}

MU_TEST_SUITE(wavefront_suite) {
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(ignoring_unrecognized_lines_tst);
	MU_RUN_TEST(vertex_records_tst);

}

int main(int argc, char *argv[]) {
	MU_RUN_SUITE(wavefront_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
