#include <stdio.h>
#include <math.h>

#define f(x) (1 / x)

int main(void)
{
  double a = 1;   // 積分区間の下端
  double b = 2;   // 積分区間の上端

  // シンプソン法
  for (int i = 1; i < 11; i++) {
    double n = pow(2, i);           // 分割数
    double h = (b - a) / (2 * n);   // 刻み幅
    double s = 0;                   // 積分値

    double s1 = 0;
    for (int j = 1; j <= 2 * n - 1; j += 2) {
      double x = a + h * j;
      s1 += 4 * f(x);
    }

    double s2 = 0;
    for (int j = 2; j <= 2 * n - 2; j += 2) {
      double x = a + h * j;
      s2 += 2 * f(x);
    }

    s = (s1 + s2 + f(a) + f(b)) * h / 3;
    printf("\n計算結果 2の%2d乗 = %f\n", i, s);
  }

  return 0;
}