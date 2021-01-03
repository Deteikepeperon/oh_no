#include <stdio.h>
#include <math.h>

#define f(x) (exp(-x))

int main(void)
{
  double a = 0.0;                 // 積分区間の下端
  double b = 1.0;                 // 積分区間の上端
  double n = 1024.0;              // 分割数
  double h = (b - a) / (2 * n);   // 刻み幅
  double s, s1, s2 = 0.0;         // 積分値


  // シンプソン法
  for (int i = 1; i <= 2 * n - 1; i += 2) {
    double x = a + h * i;
    s1 += 4 * f(x);
  }

  for (int i = 2; i <= 2 * n - 2; i += 2) {
    double x = a + h * i;
    s2 += 2 * f(x);
  }

  s = (s1 + s2 + f(a) + f(b)) * h / 3;

  printf("\n計算結果 = %f\n", s);
}