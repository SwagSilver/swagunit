#ifndef SWAGUNIT_ASSERTIONS_H
#define SWAGUNIT_ASSERTIONS_H

#ifdef __cplusplus
extern "C" {
#endif

#include "swagunit_escape.h"

#include <stdio.h>

#define __BOLD(s) BOLD #s BOLD_CLEAR

#define SWAGUNIT_FAIL_TEST(suite, msg, ...) \
	suite->last_test_result = SWAGUNIT_TEST_FAILED;\
	if (suite->output_config->colored) {\
		fprintf(suite->output_config->stream,\
				"file %s, %s at line %s: " RED "assertion failed" CLEAR " - " msg "\n",\
				__BOLD(__FILE__), __BOLD(__func__), __BOLD(__LINE__),\
				__VA_ARGS__);\
	} else {\
		fprintf(suite->output_config->stream,\
				"file %s, %s at line %d: assertion failed - " msg "\n",\
				__FILE__, __func__, __LINE__, __VA_ARGS__);\
	}

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

#endif // SWAGUNIT_ASSERTIONS_H
