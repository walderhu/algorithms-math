#include "../s21_math.h"
/*
Для расчета арккосинуса использовалось нижеприведенное тригонометрическое
тождество arccos(x) = π/2 - arcsin(x)
*/
long double s21_acos(double x) {
  if (x != x || x > 1.0 || x < -1.0) {
    x = S21_NAN;
  } else if (x == 1) {
    x = 0;
  } else if (x == -1) {
    x = S21_PI;
  } else {
    x = S21_PI_2 - s21_asin(x);
  }
  return x;
}