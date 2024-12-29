#ifndef S21_MATH_TEST_H
#define S21_MATH_TEST_H

#include <check.h>
#include <math.h>
#include <stdlib.h>
#include "../src/s21_math.h"

int run_testcase(Suite *testcase);
Suite *math_suite();
Suite *s21_log_suite();
Suite *s21_exp_suite();
Suite *s21_pow_suite();
Suite *s21_sin_suite();
Suite *s21_sqrt_suite();
Suite *s21_tan_suite();
Suite *s21_abs_suite();
Suite *s21_acos_suite();
Suite *s21_asin_suite();
Suite *s21_cos_suite();
Suite *s21_ceil_suite();
Suite *s21_atan_suite();
Suite *s21_fmod_suite();
Suite *s21_floor_suite();
Suite *s21_fabs_suite();

#endif