#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define f(x, y) (x + y)

int main(void)
{
  double n = 100000;
  double z = 0;

  // モンテカルロ法
  for (int i = 1; i <= n; i++) {
    double x = (double)rand() / RAND_MAX;
    double y = (double)rand() / RAND_MAX;
    z += f(x, y);

    if (i % 5000 == 0)  printf("\n計算結果 %7d回目 = %f\n", i, z / i);
  }
}