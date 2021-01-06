#include <stdio.h>
#include <math.h>

#define f(x, y) (x + y)

int main(void)
{
  double a = 0;     // 区間a
  double b = 2;     // 区間b
  double y0 = 1;    // 初期値 y(a)

  // ルンゲ・クッタ法
  for (int i = 1; i < 11; i++) {
    double n = pow(2, i);     // 分割数
    double h = (b - a) / n;   // 刻み幅

    double x = a;
    double y = y0;

    while (x < b) {
      double k1 = f(x, y);
      double k2 = f(x + h / 2, y + k1 * h / 2);
      double k3 = f(x + h / 2, y + k2 * h / 2);
      double k4 = f(x + h, y + k3 * h);

      y = y + h * (k1 + 2 * k2 + 2 * k3 + k4) / 6;
      x += h;
    }

    printf("\n計算結果 2の%2d乗 = %f\n", i, y);
  }

  return 0;
}