#ifndef SWAGUNIT_H
#define SWAGUNIT_H

#ifdef __cplusplus
extern "C" {
#endif

#include "swagunit_assertions.h"

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
	FILE *output_stream;
};

/**
 * Returns a test suite with the given name and output stream
 */
struct swagunit_test_suite swagunit_make_test_suite(const char *const name,
													FILE *output_stream);

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
