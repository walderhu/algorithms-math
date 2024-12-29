#include "../tests.h"

START_TEST(log_test_1) {
    double x = 1;
    ck_assert_double_eq_tol(s21_log(x), log(x), S21_EPSILON);
}
END_TEST

START_TEST(log_test_2) {
    double x = -1;
    ck_assert_ldouble_nan(s21_log(x));
    ck_assert_double_nan(log(x));
}
END_TEST

START_TEST(log_test_3) {
    double x = 0;
    ck_assert_ldouble_infinite(s21_log(x));
    ck_assert_double_infinite(log(x));
}
END_TEST

START_TEST(log_test_4) {
    double x = 999999999999;
    ck_assert_double_eq(s21_log(x), log(x));
}
END_TEST

START_TEST(log_test_5) {
    double x = -999999999999;
    ck_assert_ldouble_nan(s21_log(x));
    ck_assert_ldouble_nan(logl(x));
}
END_TEST

START_TEST(log_test_6) {
    double x = DBL_MAX;
    ck_assert_double_eq_tol(s21_log(x), log(x), S21_EPSILON);
}
END_TEST

START_TEST(log_test_7) {
    double x = -DBL_MAX;
    ck_assert_ldouble_nan(s21_log(x));
    ck_assert_double_nan(log(x));
}
END_TEST

START_TEST(log_test_8) {
    double x = 1e-9;
    ck_assert_ldouble_eq_tol(s21_log(x), log(x), S21_EPSILON);
}
END_TEST

START_TEST(log_test_9) {
    double x = -1e-9;
    ck_assert_ldouble_nan(s21_log(x));
    ck_assert_double_nan(log(x));
}
END_TEST

START_TEST(log_test_10) {
    ck_assert_ldouble_nan(s21_log(NAN));
    ck_assert_ldouble_nan(logl(NAN));
}
END_TEST

START_TEST(log_test_11) {
    ck_assert_ldouble_infinite(s21_log(INFINITY));
    ck_assert_ldouble_infinite(logl(INFINITY));
}
END_TEST

START_TEST(log_test_12) {
    for (double x = 1; x < 1e6; x += 2057) {
        ck_assert_double_eq_tol(s21_log(x), log(x), 1e-5);
    }
}
END_TEST

START_TEST(log_test_13) {
    for (double x = 1.23; x < 1e7; x += 2057.1) {
        ck_assert_double_eq_tol(s21_log(x), log(x), 1);
    }
}
END_TEST

Suite *s21_log_suite() {
    Suite *s = suite_create("\033[42m-=s21_log_test=-\033[0m");
    TCase *t = tcase_create("s21_log_test");
    tcase_set_timeout(t, 1000);
    tcase_add_test(t, log_test_1);
    tcase_add_test(t, log_test_2);
    tcase_add_test(t, log_test_3);
    tcase_add_test(t, log_test_4);
    tcase_add_test(t, log_test_5);
    tcase_add_test(t, log_test_6);
    tcase_add_test(t, log_test_7);
    tcase_add_test(t, log_test_8);
    tcase_add_test(t, log_test_9);
    tcase_add_test(t, log_test_10);
    tcase_add_test(t, log_test_11);
    tcase_add_test(t, log_test_12);
    tcase_add_test(t, log_test_13);
    suite_add_tcase(s, t);
    return s;
}