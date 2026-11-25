#include "cute-test.h"

#include <stdio.h>

static unsigned int total_tests = 0;
static unsigned int passed_tests = 0;
static unsigned int failed_tests = 0;

static unsigned int total_assertions = 0;
static unsigned int failed_assertions = 0;

void cute_test_assert(
	int result,
	const char* expression,
	const char* file,
	int line
) {
	total_assertions++;

	if (!result) {
		failed_assertions++;

		printf(
			"    FAILED: %s\n"
			"      at %s:%d\n",
			expression,
			file,
			line
		);
	}
}

void cute_test_run(const char* name, cute_test_fn function) {
	unsigned int failures_before = failed_assertions;

	printf("[ RUN      ] %s\n", name);

	total_tests++;

	function();

	if (failed_assertions == failures_before) {
		passed_tests++;
		printf("[       OK ] %s\n", name);
	} else {
		failed_tests++;
		printf("[  FAILED  ] %s\n", name);
	}
}

int cute_test_finish(void) {
	printf("\n");
	printf("Tests:      %u\n", total_tests);
	printf("Passed:     %u\n", passed_tests);
	printf("Failed:     %u\n", failed_tests);
	printf("Assertions: %u\n", total_assertions);
	printf("Failures:   %u\n", failed_assertions);

	return failed_tests == 0 ? 0 : 1;
}