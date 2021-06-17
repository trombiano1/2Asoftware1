#include <stdio.h>
#include <stdlib.h>


void print_mat(int N1, int N2, const double mat[][N2]) {
  for(int i = 0; i < N1; ++i){
    for(int j = 0; j < N2 - 1; ++j){
      printf("%.2f ",mat[i][j]);
    }
    printf("%.2f\n",mat[i][N2-1]);
    }
    // ここに、縦N1 x 横N2の大きさの行列matの中身を表示するコードを書いてください。
}


int main (int argc, char *argv[]) {
    int D = atoi(argv[1]);
    double A[D][D];  // D x D の行列
    for(int i = 0; i < D; ++i){
      for(int j = 0; j < D; ++j){
	A[i][j] = atoi(argv[j + i * D + 2]);
      }
    }

    // 結果の表示
    print_mat(D, D, A);
}
