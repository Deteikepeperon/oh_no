#include <stdio.h>

#define N 4   // 未知数をマクロ定義

void gauss_jordan(double a[N][N + 1]);


int main(void)
{
  double a[N][N + 1];   // 係数データを初期値として配列に格納

  a[0][0] =  1;  a[0][1] =  2;  a[0][2] = -3;  a[0][3] = 2;  a[0][4] =  3;
  a[1][0] =  0;  a[1][1] = -3;  a[1][2] =  2;  a[1][3] = 1;  a[1][4] =  7;
  a[2][0] = -3;  a[2][1] =  4;  a[2][2] =  1;  a[2][3] = 2;  a[2][4] =  9;
  a[3][0] =  3;  a[3][1] =  2;  a[3][2] = -3;  a[3][3] = 0;  a[3][4] = -1;

  gauss_jordan(a);
}


// ガウス・ジョルダン法（掃き出し法）
void gauss_jordan(double a[N][N + 1])
{
  double pivot;   // 掃き出しに使う対角成分

  for (int i = 0; i < N; i++) {
    pivot = a[i][i];

    for (int j = i; j < N + 1; j++)  a[i][j] /= pivot;

    for (int k = 0; k < N; k++){
      if ((k - i) != 0) {
        double t = a[k][i];

        for (int j = i; j < N + 1; j++)  a[k][j] -= t * a[i][j];
      }
    }
  }

  printf("\n%d元連立方程式\n\n", N);

  for (int i = 0; i < N; i++)  printf("解 x[%d] = %f\n", i, a[i][N]);
}