#include "../tests.h"

START_TEST(atan_test_1) {
    double x = 1;
    ck_assert_ldouble_eq_tol(s21_atan(x), atanl(x), S21_EPSILON);
}
END_TEST

START_TEST(atan_test_2) {
    double x = -1;
    ck_assert_ldouble_eq_tol(s21_atan(x), atanl(x), S21_EPSILON);
}
END_TEST

START_TEST(atan_test_3) {
    double x = 0;
    ck_assert_ldouble_eq_tol(s21_atan(x), atanl(x), S21_EPSILON);
}
END_TEST

START_TEST(atan_test_4) {
    double x = 999999999999;
    ck_assert_ldouble_eq_tol(s21_atan(x), atanl(x), S21_EPSILON);
}
END_TEST

START_TEST(atan_test_5) {
    double x = -999999999999;
    ck_assert_ldouble_eq_tol(s21_atan(x), atanl(x), S21_EPSILON);
}
END_TEST

START_TEST(atan_test_6) {
    double x = DBL_MAX;
    ck_assert_ldouble_eq_tol(s21_atan(x), atanl(x), S21_EPSILON);
}
END_TEST

START_TEST(atan_test_7) {
    double x = -DBL_MAX;
    ck_assert_ldouble_eq_tol(s21_atan(x), atanl(x), S21_EPSILON);
}
END_TEST

START_TEST(atan_test_8) {
    double x = 1e-9;
    ck_assert_ldouble_eq_tol(s21_atan(x), atanl(x), S21_EPSILON);
}
END_TEST

START_TEST(atan_test_9) {
    double x = -1e-9;
    ck_assert_ldouble_eq_tol(s21_atan(x), atanl(x), S21_EPSILON);
}
END_TEST

START_TEST(atan_test_10) {
    ck_assert_ldouble_nan(s21_atan(NAN));
    ck_assert_ldouble_nan(atan(NAN));
}
END_TEST

START_TEST(atan_test_11) {
    double x = INFINITY;
    ck_assert_ldouble_eq_tol(s21_atan(x), atanl(x), S21_EPSILON);
}
END_TEST

START_TEST(atan_test_12) {
    for (double x = 1.2345e-6; x < 1e11; x *= 3.33) {
        ck_assert_double_eq_tol(s21_atan(x), atan(x), 1e-6);
    }
}
END_TEST

START_TEST(atan_test_13) {
    double x = S21_MIN_INF;
    ck_assert_ldouble_eq_tol(s21_atan(x), atanl(x), S21_EPSILON);
}
END_TEST

Suite *s21_atan_suite() {
    Suite *s = suite_create("\033[42m-=s21_atan_test=-\033[0m");
    TCase *t = tcase_create("s21_atan_test");
    tcase_set_timeout(t, 1000);
    tcase_add_test(t, atan_test_1);
    tcase_add_test(t, atan_test_2);
    tcase_add_test(t, atan_test_3);
    tcase_add_test(t, atan_test_4);
    tcase_add_test(t, atan_test_5);
    tcase_add_test(t, atan_test_6);
    tcase_add_test(t, atan_test_7);
    tcase_add_test(t, atan_test_8);
    tcase_add_test(t, atan_test_9);
    tcase_add_test(t, atan_test_10);
    tcase_add_test(t, atan_test_11);
    tcase_add_test(t, atan_test_12);
    tcase_add_test(t, atan_test_13);
    suite_add_tcase(s, t);
    return s;
}