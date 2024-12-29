#include "../tests.h"

START_TEST(floor_test_1) {
    double x = 1;
    ck_assert_ldouble_eq_tol(s21_floor(x), floorl(x), S21_EPSILON);
}
END_TEST

START_TEST(floor_test_2) {
    double x = -1;
    ck_assert_ldouble_eq_tol(s21_floor(x), floorl(x), S21_EPSILON);
}
END_TEST

START_TEST(floor_test_3) {
    double x = 0;
    ck_assert_ldouble_eq_tol(s21_floor(x), floorl(x), S21_EPSILON);
}
END_TEST

START_TEST(floor_test_4) {
    double x = 1e-9;
    ck_assert_ldouble_eq_tol(s21_floor(x), floorl(x), S21_EPSILON);
}
END_TEST

START_TEST(floor_test_5) {
    double x = -1e-9;
    ck_assert_ldouble_eq_tol(s21_floor(x), floorl(x), S21_EPSILON);
}
END_TEST

START_TEST(floor_test_6) {
    ck_assert_ldouble_nan(s21_floor(NAN));
    ck_assert_ldouble_nan(floor(NAN));
}
END_TEST

START_TEST(floor_test_7) {
    ck_assert_ldouble_infinite(s21_floor(INFINITY));
    ck_assert_ldouble_infinite(floor(INFINITY));
}
END_TEST

START_TEST(floor_test_8) {
    for (double x = -1.2345e-15; x < 1e7; x += 349.3367) {
        ck_assert_double_eq_tol(s21_floor(x), floor(x), 1e-6);
    }
}
END_TEST

START_TEST(floor_test_9) {
    for (double x = -1.2345e7; x < 1e6; x += 34915679.3367) {
        ck_assert_double_eq_tol(s21_floor(x), floor(x), 1e-6);
    }
}
END_TEST

START_TEST(floor_test_10) {
    ck_assert_ldouble_infinite(s21_floor(S21_INF_NEG));
    ck_assert_ldouble_infinite(floor(S21_INF_NEG));
}
END_TEST

Suite *s21_floor_suite() {
    Suite *s = suite_create("\033[42m-=s21_floor_test=-\033[0m");
    TCase *t = tcase_create("s21_floor_test");
    tcase_set_timeout(t, 1000);
    tcase_add_test(t, floor_test_1);
    tcase_add_test(t, floor_test_2);
    tcase_add_test(t, floor_test_3);
    tcase_add_test(t, floor_test_4);
    tcase_add_test(t, floor_test_5);
    tcase_add_test(t, floor_test_6);
    tcase_add_test(t, floor_test_7);
    tcase_add_test(t, floor_test_8);
    tcase_add_test(t, floor_test_9);
    tcase_add_test(t, floor_test_10);
    suite_add_tcase(s, t);
    return s;
}