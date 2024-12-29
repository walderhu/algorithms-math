#include "../tests.h"

START_TEST(tan_test_1) {
    double x = 1;
    ck_assert_ldouble_eq_tol(s21_tan(x), tanl(x), S21_EPSILON);
}
END_TEST

START_TEST(tan_test_2) {
    double x = -1;
    ck_assert_ldouble_eq_tol(s21_tan(x), tanl(x), S21_EPSILON);
}
END_TEST

START_TEST(tan_test_3) {
    double x = 0;
    ck_assert_ldouble_eq_tol(s21_tan(x), tanl(x), S21_EPSILON);
}
END_TEST

START_TEST(tan_test_4) {
    double x = 1e-9;
    ck_assert_ldouble_eq_tol(s21_tan(x), tanl(x), S21_EPSILON);
}
END_TEST

START_TEST(tan_test_5) {
    double x = -1e-9;
    ck_assert_ldouble_eq_tol(s21_tan(x), tanl(x), S21_EPSILON);
}
END_TEST

START_TEST(tan_test_6) {
    ck_assert_ldouble_nan(s21_tan(NAN));
    ck_assert_ldouble_nan(tan(NAN));
}
END_TEST

START_TEST(tan_test_7) {
    ck_assert_ldouble_nan(s21_tan(INFINITY));
    ck_assert_ldouble_nan(tan(INFINITY));
}
END_TEST

START_TEST(tan_test_8) {
    for (double x = 1.2; x < 1e4; x += 78.1) {
        ck_assert_double_eq_tol(s21_tan(x), tan(x), 1e-6);
    }
}
END_TEST

Suite *s21_tan_suite() {
    Suite *s = suite_create("\033[42m-=s21_tan_test=-\033[0m");
    TCase *t = tcase_create("s21_tan_test");
    tcase_set_timeout(t, 1000);
    tcase_add_test(t, tan_test_1);
    tcase_add_test(t, tan_test_2);
    tcase_add_test(t, tan_test_3);
    tcase_add_test(t, tan_test_4);
    tcase_add_test(t, tan_test_5);
    tcase_add_test(t, tan_test_6);
    tcase_add_test(t, tan_test_7);
    tcase_add_test(t, tan_test_8);
    suite_add_tcase(s, t);
    return s;
}