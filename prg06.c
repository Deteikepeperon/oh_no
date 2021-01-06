#include <stdio.h>
#include <math.h>

#define f(x) (1 / x)

int main(void)
{
  double a = 1;    // 積分区間の下端
  double b = 2;    // 積分区間の上端

  // 台形法
  for (int i = 1; i < 11; i++) {
    double n = pow(2, i);     // 分割数
    double h = (b - a) / n;   // 刻み幅
    double s = 0;             // 積分値

    for (int j = 1; j < n; j++) {
      double x = a + h * j;
      s += 2 * f(x);
    }

    s = 0.5 * (s + f(a) + f(b)) * h;
    printf("\n計算結果 2の%2d乗 = %f\n", i, s);
  }

  return 0;
}