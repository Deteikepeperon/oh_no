#include <stdio.h>
#include <math.h>

#define N 5   // 未知数をマクロ定義

void gauss_seidel(double a[N][N + 1], double x[N], double y[N]);


int main(void)
{
  double a[N][N + 1], x[N], y[N];   // y[] ... 更新前の値， x[] ... 更新後の値

  a[0][0] =  4;  a[0][1] = -1;  a[0][2] =  0;  a[0][3] =  0;  a[0][4] = -1;  a[0][5] = 3;
  a[1][0] = -1;  a[1][1] =  4;  a[1][2] = -1;  a[1][3] =  0;  a[1][4] =  0;  a[1][5] = 3;
  a[2][0] =  0;  a[2][1] = -1;  a[2][2] =  4;  a[2][3] = -1;  a[2][4] =  0;  a[2][5] = 7;
  a[3][0] =  0;  a[3][1] =  0;  a[3][2] = -1;  a[3][3] =  4;  a[3][4] = -1;  a[3][5] = 9;
  a[4][0] = -1;  a[4][1] =  0;  a[4][2] =  0;  a[4][3] = -1;  a[4][4] =  4;  a[4][5] = 8;

  for (int i = 0; i < N; i++)  x[i] = 1.0;
  for (int i = 0; i < N; i++)  y[i] = x[i];

  gauss_seidel(a, x, y);
}


// ガウス・ザイデル法
void gauss_seidel(double a[N][N + 1], double x[N], double y[N])
{
  printf("\n%d元連立方程式\n\n", N);

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
      for (int i = 0; i < N; i++)  printf("解 x[%d] = %f\n", i + 1, x[i]);
      break;
    }

    if (k > 30)  printf("収束せず．\n");
  }
}