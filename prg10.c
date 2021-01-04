#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define f(x) (exp(-x))

int main(void)
{
  double n = 10000;
  double z = 0;


  // モンテカルロ法
  for (int i = 1; i <= n; i++) {
    double x = (double)rand() / RAND_MAX;
    z += f(x);

    if (i % 1000 == 0)  printf("\n計算結果 %d回目：%f\n", i, z / i);
  }
}