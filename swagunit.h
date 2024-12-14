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

struct swagunit_test_suite swagunit_make_test_suite(const char *const name)
{
	struct swagunit_test_suite suite;
	suite.name = strdup(name);
	suite.last_test_result = SWAGUNIT_TEST_PASSED;
	suite.tests_failed = 0;
	suite.tests_passed = 0;
	return suite;
}

void swagunit_run_test(struct swagunit_test_suite *const suite,
					   void (*fn)(struct swagunit_test_suite *const suite))
{
	fn(suite);

	switch (suite->last_test_result) {
	case SWAGUNIT_TEST_FAILED:
		suite->tests_failed++;
		suite->last_test_result = SWAGUNIT_TEST_PASSED;
		break;
	case SWAGUNIT_TEST_PASSED:
		suite->tests_passed++;
		break;
	}
}

int swagunit_finalize_test_suite(struct swagunit_test_suite suite)
{
	uint32_t tests_ran = suite.tests_failed + suite.tests_passed;

	fprintf(stderr,
			"ran %u tests from the \"%s\" test suite (%u failed, %u passed)",
			tests_ran, suite.name, suite.tests_failed, suite.tests_passed);

	if (suite.tests_failed > 0)
		return -1;

	return 0;
}

#define SWAGUNIT_ASSERT(suite, cond) \
	if (!cond) {\
		suite->last_test_result = SWAGUNIT_TEST_FAILED;\
		fprintf(stderr,\
				"file %s, %s at line %d: expected \"%s\" to be true, got false\n",\
				__FILE__, __func__, __LINE__, #cond);\
	}

#ifdef __cplusplus
}
#endif

#endif // SWAGUNIT_H
