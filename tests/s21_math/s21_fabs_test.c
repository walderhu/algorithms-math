#include "../tests.h"

START_TEST(fabs_test_1) {
    double x = 1;
    ck_assert_double_eq(s21_fabs(x), (double)fabs(x));
}
END_TEST

START_TEST(fabs_test_2) {
    double x = -1;
    ck_assert_double_eq(s21_fabs(x), fabs(x));
}
END_TEST

START_TEST(fabs_test_3) {
    double x = 0;
    ck_assert_double_eq(s21_fabs(x), fabs(x));
}
END_TEST

START_TEST(fabs_test_4) {
    double x = 727379969;
    ck_assert_double_eq(s21_fabs(x), fabs(x));
}
END_TEST

START_TEST(fabs_test_5) {
    double x = -727379969;
    ck_assert_double_eq(s21_fabs(x), fabs(x));
}
END_TEST

START_TEST(fabs_test_6) {
    double x = DBL_MAX;
    ck_assert_double_eq(s21_fabs(x), fabs(x));
}
END_TEST

START_TEST(fabs_test_7) {
    double x = -DBL_MAX;
    ck_assert_double_eq(s21_fabs(x), fabs(x));
}
END_TEST

START_TEST(fabs_test_8) {
    double x = 1e-9;
    ck_assert_double_eq(s21_fabs(x), fabs(x));
}
END_TEST

START_TEST(fabs_test_9) {
    double x = -1e-9;
    ck_assert_double_eq(s21_fabs(x), fabs(x));
}
END_TEST

Suite *s21_fabs_suite() {
    Suite *s = suite_create("\033[42m-=s21_fabs_test=-\033[0m");
    TCase *t = tcase_create("s21_fabs_test");
    tcase_set_timeout(t, 1000);
    tcase_add_test(t, fabs_test_1);
    tcase_add_test(t, fabs_test_2);
    tcase_add_test(t, fabs_test_3);
    tcase_add_test(t, fabs_test_4);
    tcase_add_test(t, fabs_test_5);
    tcase_add_test(t, fabs_test_6);
    tcase_add_test(t, fabs_test_7);
    tcase_add_test(t, fabs_test_8);
    tcase_add_test(t, fabs_test_9);

    suite_add_tcase(s, t);
    return s;
}