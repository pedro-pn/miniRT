#include "../test.h"

t_parser	parser;
int			f;

void test_setup(void) {
}

void test_teardown(void) {
	/* Nothing */
}

MU_TEST(ignoring_unrecognized_lines_tst) {
	f = open("gibberish.obj", O_RDONLY);
	parser = parser_obj_file(f);
	
	mu_check(parser.vertexes == NULL);
}


MU_TEST_SUITE(wavefront_suite) {
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(ignoring_unrecognized_lines_tst);

}

int main(int argc, char *argv[]) {
	MU_RUN_SUITE(wavefront_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
