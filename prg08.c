#include <stdio.h>

#define f(x, y) (x * y)

int main(void)
{
  double a = 0.0;           // 区間a
  double b = 1.0;           // 区間b
  double eta = 1.0;         // 初期値 y(a)
  double n = 1024.0;        // 分割数
  double h = (b - a) / n;   // 刻み幅


  // オイラー法
  double x = a;
  double y = eta;

  while (x < b) {
    y = y + h * f(x, y);
    x += h;
  }

  printf("\n計算結果 = %f\n", y);
}