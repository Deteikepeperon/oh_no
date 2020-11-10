#include <stdio.h>
#include <math.h>

#define N 3

void gauss_seidel(double a[N][N + 1], double x[N], double y[N]);


int main(void)
{
  double a[N][N + 1], x[N], y[N];   // y[] ... 更新前の値， x[] ... 更新後の値

  a[0][0] = 5;  a[0][1] = 1;  a[0][2] = 1;  a[0][3] = 10;
  a[1][0] = 1;  a[1][1] = 4;  a[1][2] = 1;  a[1][3] = 12;
  a[2][0] = 2;  a[2][1] = 1;  a[2][2] = 3;  a[2][3] = 13;

  for (int i = 0; i < N; i++)  x[i] = 1.0;
  for (int i = 0; i < N; i++)  y[i] = x[i];

  gauss_seidel(a, x, y);
}


// ガウス・ザイデル法
void gauss_seidel(double a[N][N + 1], double x[N], double y[N])
{
  // ここでは最大30回の繰り返しとして収束の判定をする
  for (int k = 1; k <= 30; k++) {
    for (int i = 0; i < N; i++) {
      double sum = 0;

      for (int j = 0; j < N; j++)  if (i != j)  sum += a[i][j] * x[j];

      x[i] = (a[i][N] - sum) / a[i][i];
    }

    double q = 0, eps = 0.0001;

    for (int i = 0; i < N; i++) {
      q += fabs(x[i] - y[i]);
      y[i] = x[i];
    }

    // 収束時， 解を出力
    if (q < eps) {
      for (int i = 0; i < N; i++)  printf("x[%d] = %f\n", i, x[i]);
      break;
    }

    if (k > 30)  printf("収束せず\n");
  }
}