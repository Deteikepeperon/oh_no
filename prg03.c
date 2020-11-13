#include <stdio.h>
#include <math.h>

double func(double x);
void regula_falsi(double a, double b);


int main(void)
{
  regula_falsi(2.5, 3);    // 初期値
}


// 方程式を定義
double func(double x)
{
  return (1.25 * sin(0.4 * x) * sin(0.6 * x)) - x * sin(x);
}


// はさみうち法
void regula_falsi(double a, double b)
{
  double c;
  double eps = 0.000001;    // 許容誤差

  do {
    c = (a * func(b) - b * func(a)) / (func(b) - func(a));

    if (func(c) == 0)           break;
    if (func(a) * func(c) < 0)  b = c;
    if (func(a) * func(c) > 0)  a = c;

  } while (fabs(func(c)) > eps);

  printf("\n根 %f\n", c);
}


