#include "../tests.h"

START_TEST(fmod_test_1) {
    double x = 1, y = 1;
    ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmodl(x, y), S21_EPSILON);
}
END_TEST

START_TEST(fmod_test_2) {
    double x = -1, y = -1;
    ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmodl(x, y), S21_EPSILON);
}
END_TEST

START_TEST(fmod_test_3) {
    double x = 1, y = 0;
    ck_assert_ldouble_nan(s21_fmod(x, y));
    ck_assert_ldouble_nan(fmod(x, y));
}
END_TEST

START_TEST(fmod_test_4) {
    double x = 0, y = 1;
    ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmodl(x, y), S21_EPSILON);
}
END_TEST

START_TEST(fmod_test_5) {
    double x = 999999999999, y = 3;
    ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmodl(x, y), S21_EPSILON);
}
END_TEST

START_TEST(fmod_test_6) {
    double x = -999999999999, y = 3;
    ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmodl(x, y), S21_EPSILON);
}
END_TEST

START_TEST(fmod_test_7) {
    double x = 1.23456e10, y = 1.23;
    ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmodl(x, y), 1e-6);
}
END_TEST

START_TEST(fmod_test_8) {
    double x = -1.23456e10, y = 1.23;
    ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmodl(x, y), 1e-6);
}
END_TEST

START_TEST(fmod_test_9) {
    double x = 1e-9, y = 10;
    ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmodl(x, y), S21_EPSILON);
}
END_TEST

START_TEST(fmod_test_10) {
    double x = -1e-9, y = 10;
    ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmodl(x, y), S21_EPSILON);
}
END_TEST

START_TEST(fmod_test_11) {
    ck_assert_ldouble_nan(s21_fmod(NAN, 14));
    ck_assert_ldouble_nan(fmod(NAN, 14));
}
END_TEST

START_TEST(fmod_test_12) {
    ck_assert_ldouble_nan(s21_fmod(14, NAN));
    ck_assert_ldouble_nan(fmod(14, NAN));
}
END_TEST

START_TEST(fmod_test_13) {
    ck_assert_ldouble_nan(s21_fmod(INFINITY, 14));
    ck_assert_ldouble_nan(fmod(INFINITY, 14));
}
END_TEST

START_TEST(fmod_test_14) {
    double x = 14, y = INFINITY;
    ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmodl(x, y), 1e6);
}
END_TEST

START_TEST(fmod_test_15) {
    for (double x = -1.2345e-15; x < 1e7; x += 349.3367) {
        ck_assert_double_eq_tol(s21_fmod(x, 3.16), fmod(x, 3.16), 1e-6);
    }
}
END_TEST

START_TEST(fmod_test_16) {
    for (double x = -1.2345e7; x < 1e10; x += 34915.3367) {
        ck_assert_double_eq_tol(s21_fmod(x, 3.16), fmod(x, 3.16), 1e-6);
    }
}
END_TEST

START_TEST(fmod_test_17) {
    for (double x = -1.2345e-15; x < 1e7; x += 349.3367) {
        ck_assert_double_eq_tol(s21_fmod(x, 3.16), fmod(x, 3.16), 1e-6);
    }
}
END_TEST

START_TEST(fmod_test_18) {
    for (double x = -1.2345e7; x < 1e15; x += 3491567999.3367) {
        ck_assert_double_eq_tol(s21_fmod(999999.999999, x), fmod(999999.999999, x), 1e-6);
    }
}
END_TEST

Suite *s21_fmod_suite() {
    Suite *s = suite_create("\033[42m-=s21_fmod_test=-\033[0m");
    TCase *t = tcase_create("s21_fmod_test");
    tcase_set_timeout(t, 1000);
    tcase_add_test(t, fmod_test_1);
    tcase_add_test(t, fmod_test_2);
    tcase_add_test(t, fmod_test_3);
    tcase_add_test(t, fmod_test_4);
    tcase_add_test(t, fmod_test_5);
    tcase_add_test(t, fmod_test_6);
    tcase_add_test(t, fmod_test_7);
    tcase_add_test(t, fmod_test_8);
    tcase_add_test(t, fmod_test_9);
    tcase_add_test(t, fmod_test_10);
    tcase_add_test(t, fmod_test_11);
    tcase_add_test(t, fmod_test_12);
    tcase_add_test(t, fmod_test_13);
    tcase_add_test(t, fmod_test_14);
    tcase_add_test(t, fmod_test_15);
    tcase_add_test(t, fmod_test_16);
    tcase_add_test(t, fmod_test_17);
    tcase_add_test(t, fmod_test_18);
    suite_add_tcase(s, t);
    return s;
}