#include <stdio.h>

#define f(x, y) (x * y)

int main(void)
{
  double a = 0.0;           // 区間a
  double b = 1.0;           // 区間b
  double y0 = 1.0;          // 初期値 y(a)
  double n = 1024.0;        // 分割数
  double h = (b - a) / n;   // 刻み幅


  // ルンゲ・クッタ法
  double x = a;
  double y = y0;

  while (x < b) {
    double k1 = f(x, y);
    double k2 = f(x + h / 2.0, y + k1 * h / 2.0);
    double k3 = f(x + h / 2.0, y + k2 * h / 2.0);
    double k4 = f(x + h, y + k3 * h);

    y = y + h * (k1 + 2.0 * k2 + 2.0 * k3 + k4) / 6.0;
    x += h;
  }

  printf("\n計算結果 = %f\n", y);
}