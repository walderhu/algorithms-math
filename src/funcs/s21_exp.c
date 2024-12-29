#include "../s21_math.h"
/*
расчитываения экспоненты e^x
https://neerc.ifmo.ru/wiki/index.php?title=%D0%A0%D0%B0%D0%B7%D0%BB%D0%BE%D0%B6%D0%B5%D0%BD%D0%B8%D0%B5_%D1%84%D1%83%D0%BD%D0%BA%D1%86%D0%B8%D0%B9_%D0%B2_%D1%81%D1%82%D0%B5%D0%BF%D0%B5%D0%BD%D0%BD%D1%8B%D0%B5_%D1%80%D1%8F%D0%B4%D1%8B#e.5Ex
n - количество количетсво членов ряда, то есть сколько итераций цикла
наш код это всего лишь програмная реализация формулы с сайта
*/
long double s21_exp(double x) {
  long double var1 = (long long int)(x / S21_LN2), result = 0;
  long double var2 = x - var1 * S21_LN2;
  int n = 16;
  if (x == S21_INF_NEG)
    result = 0;
  else if (S21_IS_NAN(x))
    result = S21_NAN;
  else if (S21_IS_INF(x))
    result = S21_INF;
  else {
    for (short i = 0; i < n; i++) result += s21_pow(var2, i) / s21_fact(i);
    result *= s21_pow(2, var1);
  }
  return result;
}