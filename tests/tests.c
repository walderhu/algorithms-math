#include "tests.h"

int main() {
    int number_failed = 0;
    int number_success = 0;
    Suite *list_cases[] = { s21_fmod_suite(), s21_floor_suite(), s21_fabs_suite(), s21_log_suite(), s21_exp_suite(), 
                            s21_pow_suite(), s21_sin_suite(), s21_sqrt_suite(), s21_abs_suite(),  s21_tan_suite(), 
                            s21_acos_suite(), s21_asin_suite(), s21_cos_suite(), s21_ceil_suite(), s21_atan_suite(), NULL};

    for (Suite **current_testcase = list_cases; *current_testcase != NULL; current_testcase++) {
        if (run_testcase(*current_testcase) != 0) number_failed++;
        else number_success ++;
    }
    printf("Success: %d\nFailures: %d\n", number_success, number_failed);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

int run_testcase(Suite *testcase) {
    int result = 1;
    SRunner *sr = srunner_create(testcase);
    srunner_run_all(sr, CK_VERBOSE);
    result = srunner_ntests_failed(sr);
    srunner_free(sr);
    return result;
}