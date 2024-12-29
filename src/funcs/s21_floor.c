#include "../s21_math.h"
/*
Функция floor() в библиотеке math.h возвращает наибольшее целое число, меньшее
или равное указанному аргументу (округление вниз).
*/
long double s21_floor(double x) {
  long double result = 0;
  if (S21_IS_NAN(x))
    result = S21_NAN;
  else if (x == S21_INF_POS)
    result = S21_INF_POS;
  else if (x == S21_INF_NEG)
    result = S21_INF_NEG;
  else {
    result = (int)x;
    result = (x < 0 && x != result) ? result - 1 : result;
  }
  return (long double)result;
}