#include <stdio.h>
#include <math.h>

#define f(x) (exp(-x))

int main(void)
{
  double a = 0.0;           // 積分区間の下端
  double b = 1.0;           // 積分区間の上端
  double n = 1024.0;        // 分割数
  double h = (b - a) / n;   // 刻み幅
  double s = 0.0;           // 積分値


  // 台形法
  for (int i = 1; i < n; i++) {
    double x = a + h * i;
    s += 2 * f(x);
  }

  s = 0.5 * (s + f(a) + f(b)) * h;

  printf("\n計算結果 = %f\n", s);
}