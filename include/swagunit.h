#ifndef SWAGUNIT_H
#define SWAGUNIT_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdint.h>
#include <string.h>

enum swagunit_test_result {
	SWAGUNIT_TEST_FAILED,
	SWAGUNIT_TEST_PASSED,
};

struct swagunit_test_suite {
	const char *name;
	enum swagunit_test_result last_test_result;
	uint32_t tests_failed, tests_passed;
};

/**
 * Returns a test suite with the given name
 */
struct swagunit_test_suite swagunit_make_test_suite(const char *const name);

/**
 * Runs the given test using the given test suite
 */
void swagunit_run_test(struct swagunit_test_suite *const suite,
					   void (*fn)(struct swagunit_test_suite *const suite));

/**
 * Finalizes running the given test suite by printing its results
 */
int swagunit_finalize_test_suite(struct swagunit_test_suite suite);

#define SWAGUNIT_FAIL_TEST(suite, msg, ...) \
	suite->last_test_result = SWAGUNIT_TEST_FAILED;\
	fprintf(stderr,\
			"file %s, %s at line %d: assertion failed - " msg "\n",\
			__FILE__, __func__, __LINE__, __VA_ARGS__);

#define SWAGUNIT_ASSERT_TRUE(suite, cond) \
	if (!cond)\
		SWAGUNIT_FAIL_TEST(suite, "expected %s to be true, got false", #cond)

#define SWAGUNIT_ASSERT_FALSE(suite, cond) \
	if (cond)\
		SWAGUNIT_FAIL_TEST(suite, "expected %s to be false, got true", #cond)

#define __STRINGIFY(a) #a

#define SWAGUNIT_ASSERT_EQ(suite, actual, expected) \
	if (expected != actual)\
		SWAGUNIT_FAIL_TEST(suite, "expected %s to be %s, got %s", #actual,\
						   #expected, __STRINGIFY((actual)))

#define SWAGUNIT_ASSERT_NEQ(suite, actual, expected) \
	if (expected == actual)\
		SWAGUNIT_FAIL_TEST(suite, "expected %s to not be %s", #actual,\
						   #expected)

#define SWAGUNIT_ASSERT_LT(suite, actual, expected) \
	if (expected >= actual)\
		SWAGUNIT_FAIL_TEST(suite, "expected %s to be lesser than %s, got %s",\
						   #actual, #expected, __STRINGIFY((actual)))

#define SWAGUNIT_ASSERT_GT(suite, actual, expected) \
	if (expected <= actual)\
		SWAGUNIT_FAIL_TEST(suite, "expected %s to be greater than %s, got %s",\
						   #actual, #expected, __STRINGIFY((actual)))

#define SWAGUNIT_ASSERT_LTE(suite, actual, expected) \
	if (expected > actual)\
		SWAGUNIT_FAIL_TEST(suite,\
						   "expected %s to be lesser than or equal to %s, got %s",\
						   #actual, #expected, __stringify((actual)))

#define SWAGUNIT_ASSERT_GTE(suite, actual, expected) \
	if (expected < actual)\
		SWAGUNIT_FAIL_TEST(suite,\
						   "expected %s to be greater than or equal to %s, got %s",\
						   #actual, #expected, __STRINGIFY((actual)))

#ifdef __cplusplus
}
#endif

#endif // SWAGUNIT_H
