#ifndef SWAGUNIT_H
#define SWAGUNIT_H

#ifdef __cplusplus
extern "C" {
#endif

#include "swagunit_assertions.h"

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

enum swagunit_test_result {
	SWAGUNIT_TEST_FAILED,
	SWAGUNIT_TEST_PASSED,
};

struct swagunit_output_config {
	FILE *stream;
	bool colored;
};

/**
 * Returns the default test output config
 *
 * @note
 * 	This function sets `.stream` to stderr internally, so this couldn't have
 * 	been a constant
 */
struct swagunit_output_config swagunit_get_default_output_config(void);

struct swagunit_test_suite {
	const char *name;
	enum swagunit_test_result last_test_result;
	uint32_t tests_failed, tests_passed;
	struct swagunit_output_config output_config;
};

/**
 * Returns a test suite with the given name and output config
 */
struct swagunit_test_suite swagunit_make_test_suite(const char *const name,
													struct swagunit_output_config output_config);

/**
 * Runs the given test using the given test suite
 */
void swagunit_run_test(struct swagunit_test_suite *const suite,
					   void (*fn)(struct swagunit_test_suite *const suite));

/**
 * Finalizes running the given test suite by printing its results
 */
int swagunit_finalize_test_suite(struct swagunit_test_suite suite);

#ifdef __cplusplus
}
#endif

#endif // SWAGUNIT_H
