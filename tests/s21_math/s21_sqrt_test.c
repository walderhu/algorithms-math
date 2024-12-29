#include "../tests.h"

START_TEST(sqrt_test_1) {
    double x = 1;
    ck_assert_ldouble_eq_tol(s21_sqrt(x), sqrtl(x), S21_EPSILON);
}
END_TEST

START_TEST(sqrt_test_2) {
    double x = -1;
    ck_assert_ldouble_nan(s21_sqrt(x));
    ck_assert_double_nan(sqrt(x));
}
END_TEST

START_TEST(sqrt_test_3) {
    double x = 0;
    ck_assert_ldouble_eq_tol(s21_sqrt(x), sqrtl(x), S21_EPSILON);
}
END_TEST

START_TEST(sqrt_test_4) {
    double x = 999999999999;
    ck_assert_ldouble_eq_tol(s21_sqrt(x), sqrtl(x), S21_EPSILON);
}
END_TEST

START_TEST(sqrt_test_5) {
    double x = -999999999999;
    ck_assert_ldouble_nan(s21_sqrt(x));
    ck_assert_ldouble_nan(sqrtl(x));
}
END_TEST

START_TEST(sqrt_test_6) {
    double x = 6.78912e16;
    ck_assert_ldouble_eq_tol(s21_sqrt(x), sqrtl(x), S21_EPSILON);
}
END_TEST

START_TEST(sqrt_test_7) {
    double x = -DBL_MAX;
    ck_assert_ldouble_nan(s21_sqrt(x));
    ck_assert_double_nan(sqrt(x));
}
END_TEST

START_TEST(sqrt_test_8) {
    double x = 1e-9;
    ck_assert_ldouble_eq_tol(s21_sqrt(x), sqrtl(x), S21_EPSILON);
}
END_TEST

START_TEST(sqrt_test_9) {
    double x = -1e-9;
    ck_assert_ldouble_nan(s21_sqrt(x));
    ck_assert_ldouble_nan(sqrtl(x));
}
END_TEST

START_TEST(sqrt_test_10) {
    ck_assert_ldouble_nan(s21_sqrt(NAN));
    ck_assert_ldouble_nan(sqrtl(NAN));
}
END_TEST

START_TEST(sqrt_test_11) {
    ck_assert_ldouble_infinite(s21_sqrt(INFINITY));
    ck_assert_ldouble_infinite(sqrtl(INFINITY));
}
END_TEST

START_TEST(sqrt_test_12) {
    for (double x = 12345e-5; x < 1e15; x *= 1.33) {
        ck_assert_ldouble_eq_tol(s21_sqrt(x), sqrtl(x), S21_EPSILON);
    }
}
END_TEST

Suite *s21_sqrt_suite() {
    Suite *s = suite_create("\033[42m-=s21_sqrt_test=-\033[0m");
    TCase *t = tcase_create("s21_sqrt_test");
    tcase_set_timeout(t, 1000);
    tcase_add_test(t, sqrt_test_1);
    tcase_add_test(t, sqrt_test_2);
    tcase_add_test(t, sqrt_test_3);
    tcase_add_test(t, sqrt_test_4);
    tcase_add_test(t, sqrt_test_5);
    tcase_add_test(t, sqrt_test_6);
    tcase_add_test(t, sqrt_test_7);
    tcase_add_test(t, sqrt_test_8);
    tcase_add_test(t, sqrt_test_9);
    tcase_add_test(t, sqrt_test_10);
    tcase_add_test(t, sqrt_test_11);
    tcase_add_test(t, sqrt_test_12);
    suite_add_tcase(s, t);
    return s;
}