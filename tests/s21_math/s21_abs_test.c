#include "../tests.h"

START_TEST(abs_test_1) {
    int x = 1;
    ck_assert_int_eq(s21_abs(x), abs(x));
}
END_TEST

START_TEST(abs_test_2) {
    int x = -1;
    ck_assert_int_eq(s21_abs(x), abs(x));
}
END_TEST

START_TEST(abs_test_3) {
    int x = 0;
    ck_assert_int_eq(s21_abs(x), abs(x));
}
END_TEST

START_TEST(abs_test_4) {
    int x = 727379969;
    ck_assert_int_eq(s21_abs(x), abs(x));
}
END_TEST

START_TEST(abs_test_5) {
    int x = -727379969;
    ck_assert_int_eq(s21_abs(x), abs(x));
}
END_TEST

START_TEST(abs_test_6) {
    int x = INT32_MAX;
    ck_assert_int_eq(s21_abs(x), abs(x));
}
END_TEST

START_TEST(abs_test_7) {
    int x = INT32_MIN;
    ck_assert_int_eq(s21_abs(x), abs(x));
}
END_TEST

START_TEST(abs_test_8) {
    int x = 1e-9;
    ck_assert_int_eq(s21_abs(x), abs(x));
}
END_TEST

START_TEST(abs_test_9) {
    int x = -1e-9;
    ck_assert_int_eq(s21_abs(x), abs(x));
}
END_TEST

Suite *s21_abs_suite() {
    Suite *s = suite_create("\033[42m-=s21_abs_test=-\033[0m");
    TCase *t = tcase_create("s21_abs_test");
    tcase_set_timeout(t, 1000);
    tcase_add_test(t, abs_test_1);
    tcase_add_test(t, abs_test_2);
    tcase_add_test(t, abs_test_3);
    tcase_add_test(t, abs_test_4);
    tcase_add_test(t, abs_test_5);
    tcase_add_test(t, abs_test_6);
    tcase_add_test(t, abs_test_7);
    tcase_add_test(t, abs_test_8);
    tcase_add_test(t, abs_test_9);
    suite_add_tcase(s, t);
    return s;
}