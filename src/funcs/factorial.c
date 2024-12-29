#include "../s21_math.h"
/*
Программная интерпритация факториала
Формулу можно найти:
https://ru.wikipedia.org/wiki/%D0%A4%D0%B0%D0%BA%D1%82%D0%BE%D1%80%D0%B8%D0%B0%D0%BB
*/
long double s21_fact(int x) {
  return (x == 0 || x == 1) ? 1 : x * s21_fact(x - 1);
}