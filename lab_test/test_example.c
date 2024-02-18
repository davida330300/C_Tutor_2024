// test_example.c
#include <check.h>
#include "example.h"
#include <stdlib.h>


// Define unit tests
START_TEST(test_add_positive_numbers) {
    ck_assert_int_eq(add(2, 3), 5);
}

START_TEST(test_add_negative_numbers) {
    ck_assert_int_eq(add(-2, -3), -5);
}

START_TEST(test_add_mixed_numbers) {
    ck_assert_int_eq(add(-2, 3), 1);
}

Suite *example_suite(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("Example");

    // Core test case
    tc_core = tcase_create("Core");
    tcase_add_test(tc_core, test_add_positive_numbers);
    tcase_add_test(tc_core, test_add_negative_numbers);
    tcase_add_test(tc_core, test_add_mixed_numbers);
    suite_add_tcase(s, tc_core);

    return s;
}

int main(void) {
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = example_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
