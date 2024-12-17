#include "swagunit.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>

struct swagunit_output_config swagunit_get_default_output_config(void)
{
	struct swagunit_output_config config;
	config.stream = stderr;
	config.colored = true;
	return config;
}

struct swagunit_test_suite swagunit_make_test_suite(const char *const name,
													struct swagunit_output_config output_config)
{
	struct swagunit_test_suite suite;
	suite.name = strdup(name);
	suite.last_test_result = SWAGUNIT_TEST_PASSED;
	suite.tests_failed = 0;
	suite.tests_passed = 0;
	suite.output_config = output_config;
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
	case SWAGUNIT_TEST_SKIPPED:
		suite->tests_skipped++;
		break;
	}
}

int swagunit_finalize_test_suite(struct swagunit_test_suite suite)
{
	uint32_t tests_ran =
		suite.tests_failed + suite.tests_passed + suite.tests_skipped;

	fprintf(stderr,
			"ran %u tests from the \"%s\" test suite (%u failed, %u passed, %u skipped)\n",
			tests_ran, suite.name, suite.tests_failed, suite.tests_passed,
			suite.tests_skipped);

	if (suite.tests_failed > 0)
		return -1;

	return 0;
}
