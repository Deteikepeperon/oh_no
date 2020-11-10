#include <stdio.h>

#define N 3

void row_reduction(double a[][N + 1]);


int main(void)
{
  double a[N][N + 1];

  a[0][0] = 2;  a[0][1] = 2;  a[0][2] =  6;  a[0][3] = 24;
  a[1][0] = 3;  a[1][1] = 5;  a[1][2] = 13;  a[1][3] = 52;
  a[2][0] = 5;  a[2][1] = 8;  a[2][2] = 24;  a[2][3] = 93;

  row_reduction(a);
}


// 掃き出し法
void row_reduction(double a[][N + 1])
{
  double pivot, t;

  for (int i = 0; i < N; i++) {
    pivot = a[i][i];

    for (int j = i; j < N + 1; j++)  a[i][j] = a[i][j] / pivot;

    for (int k = 0; k < N; k++){
      if ((k - i) != 0) {
        t = a[k][i];

        for (int j = i; j < N + 1; j++)  a[k][j] = a[k][j] - t * a[i][j];
      }
    }
  }

  for (int i = 0; i < N; i++)  printf("x[%d] = %f\n", i, a[i][N]);
}