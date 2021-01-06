#include <stdio.h>
#include <math.h>

#define f(x, y) (x + y)

int main(void)
{
  double a = 0;     // 区間a
  double b = 2;     // 区間b
  double eta = 1;   // 初期値 y(a)

  // オイラー法
  for (int i = 1; i < 11; i++) {
    double n = pow(2, i);     // 分割数
    double h = (b - a) / n;   // 刻み幅

    double x = a;
    double y = eta;

    while (x < b) {
      y = y + h * f(x, y);
      x += h;
    }

    printf("\n計算結果 2の%2d乗 = %f\n", i, y);
  }

  return 0;
}