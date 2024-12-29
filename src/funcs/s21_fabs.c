#include "../s21_math.h"
/*
Функция fabs() в библиотеке math.h используется для вычисления абсолютного
значения числа (модуля числа).
*/
long double s21_fabs(double x) {
  if (x == S21_INF_POS || x == S21_INF_NEG)
    x = S21_INF_POS;
  else if (x < 0)
    x *= -1;
  return x;
}