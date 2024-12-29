#include "../s21_math.h"

long double s21_pow(double base, double exp) {
  long double result;
  if ((base == S21_INF_NEG && exp == S21_INF_NEG) ||
      (s21_fabs(base) < S21_EPSILON && exp == S21_INF_POS))
    result = 0;
  else if ((base == S21_INF_NEG && exp == S21_INF_POS) ||
           (s21_fabs(base) < S21_EPSILON && exp < 0))
    result = S21_INF_POS;
  else if ((long double)(long long int)exp == exp) {
    result = 1;
    if (exp > 0)
      for (int i = 0; i < exp; i++) result *= base;
    else
      for (int i = 0; i < -exp; i++) result /= base;
  } else {
    result = (base >= 0) ? s21_exp(exp * s21_log(base)) : S21_NAN;
  }
  return result;
}