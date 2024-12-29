#include "../s21_math.h"
/*
sin(pi/2 - x) = cos(x)
https://socratic.org/questions/how-do-you-verify-the-identity-sin-pi-2-x-cosx
Наш код есть просто програмная интерпритация формулы выше
*/
long double s21_cos(double x) {
  return (S21_IS_NAN(x) || S21_IS_INF(x)) ? S21_NAN : s21_sin(S21_PI / 2 - x);
}