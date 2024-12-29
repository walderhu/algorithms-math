#include "../s21_math.h"
/*
Функция fmod() в библиотеке math.h используется для вычисления остатка от
деления двух чисел с плавающей точкой.
*/
long double s21_fmod(double x, double y) {
  long double result;
  if (y == 0 || S21_IS_INF(x) || S21_IS_NAN(x) || S21_IS_NAN(y))
    result = S21_NAN;
  else if (S21_IS_INF(y))
    result = x;
  else if (x == y)
    result = 0;
  else {
    short flag = 0;
    if (x < 0.0) {
      x *= -1;
      ++flag;
    }
    if (y < 0.0) y *= -1;
    long long int var = x / y;
    x = (long double)x - var * (long double)y;
    result = !flag ? x : -x;
  }
  return result;
}