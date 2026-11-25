#ifndef CUTE_TEST_H
#define CUTE_TEST_H

#include <string.h>

typedef void (*cute_test_fn)(void);

void cute_test_run(const char* name, cute_test_fn function);

void cute_test_assert(
	int result,
	const char* expression,
	const char* file,
	int line
);

int cute_test_finish(void);

#define CUTE_TEST(name) \
	static void name(void)

#define CUTE_RUN(name) \
	cute_test_run(#name, name)

#define CUTE_ASSERT(expression) \
	cute_test_assert( \
		!!(expression), \
		#expression, \
		__FILE__, \
		__LINE__ \
	)

#define CUTE_ASSERT_EQ(a, b) \
	CUTE_ASSERT((a) == (b))

#define CUTE_ASSERT_NE(a, b) \
	CUTE_ASSERT((a) != (b))

#define CUTE_ASSERT_STR_EQ(a, b) \
	CUTE_ASSERT(strcmp((a), (b)) == 0)

#define CUTE_ASSERT_NULL(value) \
	CUTE_ASSERT((value) == NULL)

#define CUTE_ASSERT_NOT_NULL(value) \
	CUTE_ASSERT((value) != NULL)

#endif
