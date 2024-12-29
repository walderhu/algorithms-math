#include "../s21_math.h"
/*
Реализация через ряды Тейлора
https://habr.com/ru/articles/527226/
n - количество членов в ряду, при точности 16 чисел
*/
long double s21_sin(double x) {
  long double result = 0;
  if (S21_IS_NAN(x) || S21_IS_INF(x))
    result = S21_NAN;
  else if (x == M_NULL)
    result = M_NULL;
  else {
    int n = 15;
    x = s21_fmod(x, 2 * S21_PI);
    for (int i = 0; i < n; i++)
      result +=
          (s21_pow(-1, i) * s21_pow(x, 2 * i + 1)) / (s21_fact(2 * i + 1));
  }
  return result;
}