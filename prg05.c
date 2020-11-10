#include <stdio.h>

#define N 4     // データ個数

double a[2];    // 切片と傾きを入れるグローバル変数

void least_square(double x[N], double y[N]);


int main(void)
{
  double x[N] = {1, 2, 3, 4};
  double y[N] = {9, 34, 85, 171};

  least_square(x, y);
  printf("y = %lfx + %lfx\n", a[1], a[0]);   // 近似曲線
}


// 最小二乗法
void least_square(double x[N], double y[N])
{
  double sum_x2 = 0, sum_xy = 0, sum_x = 0, sum_y = 0;

  for (int i = 0; i < N; i++) {
    sum_x2 += x[i] * x[i];
    sum_xy += x[i] * y[i];
    sum_x  += x[i];
    sum_y  += y[i];
  }

  a[0] = (sum_x2 * sum_y - sum_x * sum_xy) / (N * sum_x2 - sum_x * sum_x);
  a[1] = (N * sum_xy - sum_x * sum_y) / (N * sum_x2 - sum_x * sum_x);
}