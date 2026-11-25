#include "cute-test.h"

// Basic assertion tests

CUTE_TEST(assert_true) {
	CUTE_ASSERT(1);
}

CUTE_TEST(assert_false_expression) {
	CUTE_ASSERT(!0);
}

CUTE_TEST(assert_equal_integers) {
	CUTE_ASSERT_EQ(42, 42);
}

CUTE_TEST(assert_not_equal_integers) {
	CUTE_ASSERT_NE(42, 24);
}

CUTE_TEST(assert_equal_expressions) {
	CUTE_ASSERT_EQ(10 + 5, 15);
}

CUTE_TEST(assert_boolean_expression) {
	CUTE_ASSERT(5 > 2);
}

/* Multiple assertions in one test */

CUTE_TEST(multiple_assertions) {
	CUTE_ASSERT_EQ(1 + 1, 2);
	CUTE_ASSERT_EQ(2 * 3, 6);
	CUTE_ASSERT_NE(10 / 2, 6);
}

/* More realistic examples */

CUTE_TEST(string_comparison) {
	const char* first = "cute";
	const char* second = "cute";

	CUTE_ASSERT_EQ(first[0], second[0]);
	CUTE_ASSERT_EQ(first[1], second[1]);
}

CUTE_TEST(array_access) {
	int values[] = {10, 20, 30, 40};

	CUTE_ASSERT_EQ(values[0], 10);
	CUTE_ASSERT_EQ(values[3], 40);
}

int main(void) {
	CUTE_RUN(assert_true);
	CUTE_RUN(assert_false_expression);
	CUTE_RUN(assert_equal_integers);
	CUTE_RUN(assert_not_equal_integers);
	CUTE_RUN(assert_equal_expressions);
	CUTE_RUN(assert_boolean_expression);
	CUTE_RUN(multiple_assertions);
	CUTE_RUN(string_comparison);
	CUTE_RUN(array_access);

	return cute_test_finish();
}
