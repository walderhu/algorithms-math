#include "../tests.h"

START_TEST(pow_test_1) {
    double x = 1;
    double y = 1;
    ck_assert_double_eq_tol(s21_pow(x, y), pow(x, y), S21_EPSILON);
}
END_TEST

START_TEST(pow_test_2) {
    double x = -1;
    double y = -1;
    ck_assert_double_eq_tol(s21_pow(x, y), pow(x, y), S21_EPSILON);
}
END_TEST

START_TEST(pow_test_3) {
    double x = 0;
    double y = 0;
    ck_assert_double_eq_tol(s21_pow(x, y), pow(x, y), S21_EPSILON);
}
END_TEST

START_TEST(pow_test_4) {
    long double x = 9999999;
    long double y = 2;
    ck_assert_ldouble_eq_tol(s21_pow(x, y), pow(x, y), S21_EPSILON);
}
END_TEST

START_TEST(pow_test_5) {
    double x = -999999999999;
    double y = -9;
    ck_assert_double_eq_tol(s21_pow(x, y), pow(x, y), S21_EPSILON);
}
END_TEST

START_TEST(pow_test_6) {
    double x = 1e-9;
    double y = 5;
    ck_assert_double_eq_tol(s21_pow(x, y), pow(x, y), S21_EPSILON);
}
END_TEST

START_TEST(pow_test_7) {
    double x = -1e-9;
    double y = 5;
    ck_assert_ldouble_eq_tol(s21_pow(x, y), powl(x, y), S21_EPSILON);
}
END_TEST

START_TEST(pow_test_8) {
    double y= 5;
    for (double x = 1.2; x < 100; x += 2) {
        ck_assert_double_eq_tol(s21_pow(x, y), pow(x, y), 1e-5);
    }
}
END_TEST

START_TEST(pow_test_9) {
    double x = 5;
    double y = 5.5;
    ck_assert_double_eq_tol(s21_pow(x, y), pow(x, y), S21_EPSILON);
}
END_TEST

START_TEST(pow_test_10) {
    double x = S21_INF_NEG;
    double y = S21_INF_POS;
    ck_assert_ldouble_infinite(s21_pow(x, y));
    ck_assert_ldouble_infinite(pow(x, y));
}
END_TEST

START_TEST(pow_test_11) {
    double x = S21_INF_NEG;
    double y = S21_INF_NEG;
    ck_assert_double_eq_tol(s21_pow(x, y), pow(x, y), S21_EPSILON);
}
END_TEST

Suite *s21_pow_suite() {
    Suite *s = suite_create("\033[42m-=s21_pow_test=-\033[0m");
    TCase *t = tcase_create("s21_pow_test");
    tcase_set_timeout(t, 1000);
    tcase_add_test(t, pow_test_1);
    tcase_add_test(t, pow_test_2);
    tcase_add_test(t, pow_test_3);
    tcase_add_test(t, pow_test_4);
    tcase_add_test(t, pow_test_5);
    tcase_add_test(t, pow_test_6);
    tcase_add_test(t, pow_test_7);
    tcase_add_test(t, pow_test_8);
    tcase_add_test(t, pow_test_9);
    tcase_add_test(t, pow_test_10);
    tcase_add_test(t, pow_test_11);
    suite_add_tcase(s, t);
    return s;
}