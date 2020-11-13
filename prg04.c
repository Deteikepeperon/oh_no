#include <stdio.h>
#include <math.h>

double func(double x);
double dfunc(double x);
void newton_method(double x0);


// ニュートン法
int main(void)
{
  newton_method(1.5);
}


// 非線形方程式
double func(double x)
{
  return x * x - 2;
}


// 非線形方程式の導関数（定義しておく）
double dfunc(double x)
{
  return 2 * x;
}


// ニュートン法
void newton_method(double x0)   // 初期値
{
  double dx, x1;
  double eps = 0.000001;        // 許容誤差

  do {
    double fx0 = func(x0);
    double dx0 = dfunc(x0);

    x1 = x0 - fx0 / dx0;
    dx = fabs(x1 - x0);
    x0 = x1;

  } while (dx > eps);

  printf("\n根 %f\n", x0);
}