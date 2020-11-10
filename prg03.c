#include <stdio.h>
#include <math.h>

double func(double x);
double regula_falsi(double a, double b);


int main(void)
{
  double alpha = regula_falsi(0.5, 2);

  printf("%f\n", alpha);
}


// 代数方程式を定義
double func(double x)
{
  return x * x - 1;
}


// 挟み撃ち法
double regula_falsi(double a, double b)
{
  double c;
  double eps = 0.000001;

  do {
    c = (a * func(b) - b * func(a)) / (func(b) - func(a));

    if (func(c) == 0)           break;
    if (func(a) * func(c) < 0)  b = c;
    if (func(a) * func(c) > 0)  a = c;

  } while (fabs(func(c)) > eps);

  return c;
}

