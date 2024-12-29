#include "../tests.h"

START_TEST(acos_test_1) {
    double x = 1;
    ck_assert_ldouble_eq_tol(s21_acos(x), acosl(x), S21_EPSILON);
}
END_TEST

START_TEST(acos_test_2) {
    double x = -1;
    ck_assert_ldouble_eq_tol(s21_acos(x), acosl(x), S21_EPSILON);
}
END_TEST

START_TEST(acos_test_3) {
    double x = 0;
    ck_assert_ldouble_eq_tol(s21_acos(x), acosl(x), S21_EPSILON);
}
END_TEST

START_TEST(acos_test_4) {
    double x = 1.000001;
    ck_assert_ldouble_nan(s21_acos(x));
    ck_assert_ldouble_nan(acos(x));
}
END_TEST

START_TEST(acos_test_5) {
    double x = -1.000001;
    ck_assert_ldouble_nan(s21_acos(x));
    ck_assert_ldouble_nan(acos(x));
}
END_TEST

START_TEST(acos_test_6) {
    ck_assert_ldouble_nan(s21_acos(NAN));
    ck_assert_ldouble_nan(acos(NAN));
}
END_TEST

START_TEST(acos_test_7) {
    ck_assert_ldouble_nan(s21_acos(INFINITY));
    ck_assert_ldouble_nan(acos(INFINITY));
}
END_TEST

START_TEST(acos_test_8) {
    double x = 1e-9;
    ck_assert_ldouble_eq_tol(s21_acos(x), acosl(x), S21_EPSILON);
}
END_TEST

START_TEST(acos_test_9) {
    double x = -1e-9;
    ck_assert_ldouble_eq_tol(s21_acos(x), acosl(x), S21_EPSILON);
}
END_TEST

START_TEST(acos_test_10) {
    ck_assert_ldouble_nan(s21_acos(NAN));
    ck_assert_ldouble_nan(acos(NAN));
}
END_TEST

START_TEST(acos_test_11) {
    ck_assert_ldouble_nan(s21_acos(INFINITY));
    ck_assert_ldouble_nan(acos(INFINITY));
}
END_TEST

START_TEST(acos_test_12) {
    for (double x = -1; x < 1; x += 0.00512345) {
        ck_assert_double_eq_tol(s21_acos(x), acos(x), 1e-6);
    }
}
END_TEST

Suite *s21_acos_suite() {
    Suite *s = suite_create("\033[42m-=s21_acos_test=-\033[0m");
    TCase *t = tcase_create("s21_acos_test");
    tcase_set_timeout(t, 1000);
    tcase_add_test(t, acos_test_1);
    tcase_add_test(t, acos_test_2);
    tcase_add_test(t, acos_test_3);
    tcase_add_test(t, acos_test_4);
    tcase_add_test(t, acos_test_5);
    tcase_add_test(t, acos_test_6);
    tcase_add_test(t, acos_test_7);
    tcase_add_test(t, acos_test_8);
    tcase_add_test(t, acos_test_9);
    tcase_add_test(t, acos_test_10);
    tcase_add_test(t, acos_test_11);
    tcase_add_test(t, acos_test_12);
    suite_add_tcase(s, t);
    return s;
}