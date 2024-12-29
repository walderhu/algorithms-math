#include "../tests.h"

START_TEST(ceil_test_1) {
    double x = 1;
    ck_assert_ldouble_eq_tol(s21_ceil(x), ceill(x), S21_EPSILON);
}
END_TEST

START_TEST(ceil_test_2) {
    double x = -1;
    ck_assert_ldouble_eq_tol(s21_ceil(x), ceill(x), S21_EPSILON);
}
END_TEST

START_TEST(ceil_test_3) {
    double x = 0;
    ck_assert_ldouble_eq_tol(s21_ceil(x), ceill(x), S21_EPSILON);
}
END_TEST

START_TEST(ceil_test_4) {
    double x = 999999999999;
    ck_assert_ldouble_eq_tol(s21_ceil(x), ceill(x), S21_EPSILON);
}
END_TEST

START_TEST(ceil_test_5) {
    double x = -999999999999;
    ck_assert_ldouble_eq_tol(s21_ceil(x), ceill(x), S21_EPSILON);
}
END_TEST

START_TEST(ceil_test_6) {
    double x = 1.23456e10;
    ck_assert_ldouble_eq_tol(s21_ceil(x), ceill(x), S21_EPSILON);
}
END_TEST

START_TEST(ceil_test_7) {
    double x = -1.23456e10;;
    ck_assert_ldouble_eq_tol(s21_ceil(x), ceill(x), S21_EPSILON);
}
END_TEST

START_TEST(ceil_test_8) {
    double x = 1e-9;
    ck_assert_ldouble_eq_tol(s21_ceil(x), ceill(x), S21_EPSILON);
}
END_TEST

START_TEST(ceil_test_9) {
    double x = -1e-9;
    ck_assert_ldouble_eq_tol(s21_ceil(x), ceill(x), S21_EPSILON);
}
END_TEST

START_TEST(ceil_test_10) {
    ck_assert_ldouble_nan(s21_ceil(NAN));
    ck_assert_ldouble_nan(ceil(NAN));
}
END_TEST

START_TEST(ceil_test_11) {
    ck_assert_ldouble_infinite(s21_ceil(INFINITY));
    ck_assert_ldouble_infinite(ceil(INFINITY));
}
END_TEST

START_TEST(ceil_test_12) {
    for (double x = -1.2345e-15; x < 1e7; x += 349.3367) {
        ck_assert_double_eq_tol(s21_ceil(x), ceil(x), 1e-6);
    }
}
END_TEST

START_TEST(ceil_test_13) {
    for (double x = -1.2345e7; x < 1e15; x += 3491567999.3367) {
        ck_assert_double_eq_tol(s21_ceil(x), ceil(x), 1e-6);
    }
}
END_TEST

Suite *s21_ceil_suite() {
    Suite *s = suite_create("\033[42m-=s21_ceil_test=-\033[0m");
    TCase *t = tcase_create("s21_ceil_test");
    tcase_set_timeout(t, 1000);
    tcase_add_test(t, ceil_test_1);
    tcase_add_test(t, ceil_test_2);
    tcase_add_test(t, ceil_test_3);
    tcase_add_test(t, ceil_test_4);
    tcase_add_test(t, ceil_test_5);
    tcase_add_test(t, ceil_test_6);
    tcase_add_test(t, ceil_test_7);
    tcase_add_test(t, ceil_test_8);
    tcase_add_test(t, ceil_test_9);
    tcase_add_test(t, ceil_test_10);
    tcase_add_test(t, ceil_test_11);
    tcase_add_test(t, ceil_test_12);
    tcase_add_test(t, ceil_test_13);
    suite_add_tcase(s, t);
    return s;
}