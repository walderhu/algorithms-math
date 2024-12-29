#ifndef S21_MATH_H
#define S21_MATH_H
#include <stdio.h>
#include <stdlib.h>

#define S21_LN2 0.693147180559945309417232
#define S21_E 2.71828182845904523536
#define S21_EPSILON 1e-7
#define S21_NAN 0.0 / 0.0
#define S21_PI 3.14159265358979323846
#define S21_PI_2 1.57079632679489661923132169163975144
#define S21_PI_12 (S21_PI / 12.)
#define S21_PI_6 (S21_PI / 6.)
#define PI2 6.28318530718
#define M_NULL -0.0
#define S21_INF_POS +1.0 / 0.0
#define S21_INF_NEG -1.0 / 0.0

// макросы
#define S21_MIN_INF \
  -__builtin_huge_vall()  // представляет отрицательную бесконечность в типе
                          // long double
#define S21_INF \
  __builtin_huge_vall()  // представляет положительную бесконечность в типе long
                         // double
#define S21_NAN_VAL \
  (__builtin_nanf(""))  // представляет значение NaN типа float.
#define S21_IS_NAN(x) \
  __builtin_isnan(x)  // возвращает ненулевое значение, если x является NaN, и
                      // ноль в противном случае
#define S21_IS_INF(x) \
  __builtin_isinf_sign(x)  // возвращает ненулевое значение, если x является
                           // бесконечностью, и ноль в противном случае.

//Основные функции по заданию
int s21_abs(int x);
long double s21_acos(double x);
long double s21_asin(double x);
long double s21_atan(double x);
long double s21_ceil(double x);
long double s21_cos(double x);
long double s21_exp(double x);
long double s21_fabs(double x);
long double s21_floor(double x);
long double s21_fmod(double x, double y);
long double s21_log(double x);
long double s21_pow(double base, double exp);
long double s21_sin(double x);
long double s21_sqrt(double x);
long double s21_tan(double x);
//Вспомогательные функции
long double s21_fact(int x);
long double s21_pow_int(double base, long int exp);
long double s21_pown(long double base, long double exp);
long double s21_powq(double base, double exp);
#endif