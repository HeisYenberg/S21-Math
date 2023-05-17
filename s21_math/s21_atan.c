#include "s21_math.h"

long double s21_atan(double x) {
  long double result = 0;
  if (x != x)
    result = x;
  else if (x == 0)
    result = x;
  else if (x == -S21_INF)
    result = -S21_M_PI_2;
  else if (x == S21_INF)
    result = S21_M_PI_2;
  else if (s21_fabs(x) == 1)
    result = S21_M_PI_4 * x;
  else if (s21_fabs(x) < 1) {
    for (int i = 0; i < 5000; i++) {
      result += (s21_pow(-1, i) * s21_pow(x, 1 + 2 * i)) / (1 + 2 * i);
    }
  } else if (s21_fabs(x) > 1) {
    for (int i = 0; i < 5000; i++)
      result += (s21_pow(-1, i) * s21_pow(x, -1 - 2 * i)) / (1 + 2 * i);
    result = ((S21_M_PI * s21_sqrt(x * x)) / (2 * x)) - result;
  }
  return result;
}