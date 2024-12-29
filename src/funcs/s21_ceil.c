#include "../s21_math.h"
/*
Функция ceil() в библиотеке math.h возвращает наименьшее целое число, большее
или равное указанному аргументу (округление вверх)
rounded - округленный х
*/
long double s21_ceil(double x) {
  if (S21_IS_INF(x))
    x = S21_INF;
  else if (S21_IS_NAN(x))
    x = S21_NAN;
  else if (!S21_IS_NAN(x) || !-S21_IS_INF(x) || x != 0) {
    long double rounded_x = (long long int)x;
    if (s21_fabs(x) > 0 && (x != rounded_x) && (x > 0)) rounded_x += 1;
    x = rounded_x;
  }
  return x;
}