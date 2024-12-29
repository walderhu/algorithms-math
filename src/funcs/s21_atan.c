#include "../s21_math.h"

/*
n - количетсво членов ряда Тейлора, то есть сколько итераций цикла
*/
long double s21_atan(double x) {
  long double result = 0;
  int n = 1200;
  if (x != x) {
    result = -S21_NAN;
  } else if (x == S21_INF) {
    result = S21_PI_2;
  } else if (x == S21_MIN_INF) {
    result = -S21_PI_2;
  } else if (x == 1) {
    result = S21_PI_2 / 2;
  } else if (x == -1) {
    result = -S21_PI_2 / 2;
  } else {
    if (-1. < x && x < 1.) {
      for (register int i = 0; i < n; i++) {
        result += s21_pow(-1, i) * s21_pow(x, 1 + (2 * i)) / (1 + (2 * i));
      }
    } else {
      for (register int i = 0; i < n; i++) {
        result += s21_pow(-1, i) * s21_pow(x, -1 - (2 * i)) / (1 + (2 * i));
      }
      result = (x > 0) ? S21_PI_2 - result : -S21_PI_2 - result;
    }
  }
  return result;
}