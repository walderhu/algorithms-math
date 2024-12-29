#include "../tests.h"

START_TEST(exp_test_1) {
    double x = 1;
    ck_assert_ldouble_eq_tol(s21_exp(x), exp(x), S21_EPSILON);
}
END_TEST

START_TEST(exp_test_2) {
    double x = -1;
    ck_assert_ldouble_eq_tol(s21_exp(x), exp(x), S21_EPSILON);
}
END_TEST

START_TEST(exp_test_3) {
    double x = 0;
    ck_assert_ldouble_eq_tol(s21_exp(x), exp(x), S21_EPSILON);
}
END_TEST

START_TEST(exp_test_4) {
    double x = 1e-9;
    ck_assert_ldouble_eq_tol(s21_exp(x), exp(x), S21_EPSILON);
}
END_TEST

START_TEST(exp_test_5) {
    double x = -1e-9;
    ck_assert_ldouble_eq_tol(s21_exp(x), exp(x), S21_EPSILON);
}
END_TEST

START_TEST(exp_test_6) {
    ck_assert_ldouble_nan(s21_exp(NAN));
    ck_assert_ldouble_nan(exp(NAN));
}
END_TEST

START_TEST(exp_test_7) {
    ck_assert_ldouble_infinite(s21_exp(INFINITY));
    ck_assert_ldouble_infinite(exp(INFINITY));
}
END_TEST

START_TEST(exp_test_8) {
    ck_assert_ldouble_eq_tol(s21_exp(-INFINITY), exp(-INFINITY), S21_EPSILON);
}
END_TEST

START_TEST(exp_test_9) {
    for (double x = -20; x < 20; x += 0.1) {
        ck_assert_double_eq_tol(s21_exp(x), exp(x), 1e-6);
    }
}
END_TEST

Suite *s21_exp_suite() {
    Suite *s = suite_create("\033[42m-=s21_exp_test=-\033[0m");
    TCase *t = tcase_create("s21_exp_test");
    tcase_set_timeout(t, 1000);
    tcase_add_test(t, exp_test_1);
    tcase_add_test(t, exp_test_2);
    tcase_add_test(t, exp_test_3);
    tcase_add_test(t, exp_test_4);
    tcase_add_test(t, exp_test_5);
    tcase_add_test(t, exp_test_6);
    tcase_add_test(t, exp_test_7);
    tcase_add_test(t, exp_test_8);
    tcase_add_test(t, exp_test_9);
    suite_add_tcase(s, t);
    return s;
}