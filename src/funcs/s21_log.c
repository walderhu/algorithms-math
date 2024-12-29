#include "../s21_math.h"
/*
n - количество количетсво членов ряда, то есть сколько итераций цикла
*/
long double s21_log(double x) {
  long double result = 0;
  if (x == S21_INF_POS)
    result = x;
  else if (x == 0)
    result = S21_INF_NEG;
  else if (x == 1)
    result = 0;
  else if (x < 0 || S21_IS_NAN(x))
    result = S21_NAN;
  else {
    int ex_pow = 0, n = 100;
    for (; x >= S21_E; x /= S21_E, ex_pow++) continue;
    for (int i = 0; i < n; i++)
      result += 2 * (x - s21_exp(result)) / (x + s21_exp(result));
    result += ex_pow;
  }
  return result;
}