#include <stdio.h>
#include <stdlib.h>


void print_mat(int N1, int N2, double mat[][N2]) {
  for(int i = 0; i < N1; ++i){
    for(int j = 0; j < N2 - 1; ++j){
      printf("%.2f ",mat[i][j]);
    }
    printf("%.2f\n",mat[i][N2-1]);
  }
}

void dot(int N1, int N2, int N3, const double mat1[][N2], const double mat2[][N3], double dst[][N3]) {
  int temp = 0;
    // ここに、N1 x N2 の行列mat1, N2 x N3 の行列mat2、N1 x N3 の行列dstを受け取り、
    // 行列積 mat1 * mat2 = dst を計算するコードを書いてください。
  for(int i = 0; i < N3; ++i){
    for(int j = 0; j < N1; ++j){
      for(int k = 0; k < N2; ++k){
	temp += mat1[j][k]*mat2[k][i];
      }
      dst[i][j] = temp;
      temp = 0;
    }
  }
}

void copy(int N1, int N2, const double mat[][N2], double dst[][N2]) {
    // ここに、N1 x N2 の行列matおよびdstを受け取り、matの内容をdstにコピーするコードを書いてください。
  for(int i = 0; i < N1; ++i){
    for(int j = 0; j < N2; ++j){
      dst[i][j] = mat[i][j];
    }
  }
}

void transpose(int N1, int N2, const double mat[][N2], double dst[][N1]) {
    // ここに、N1 x N2 の行列mat、および N2 x N1 の行列dstを受け取り、matの転置をdstに書き込むコードを書いてください。
  for(int i = 0; i < N2; ++i){
    for(int j = 0; j < N1; ++j){
      dst[i][j] = mat[j][i];
    }
  }
}

int main (int argc, char *argv[]) {
    int D = atoi(argv[1]);
    double A[D][D]; // D x D の行列

    // ここに、argvから値を読み込み、Aを埋めるコードを書いてください。
    for(int i = 0; i < D; ++i){
      for(int j = 0; j < D; ++j){
	A[i][j] = atoi(argv[j + i * D + 2]);
      }
    }

    double x[D][1]; // D x 1 の縦ベクトル
    for (int d = 0; d < D; ++d) {
        x[d][0] = (double) d;
    }
    // x は [0, 1, 2, 3, ...]^T

    // Check dot
    double ret[D][1];
    dot(D, D, 1, A, x, ret);  // ret = A * x
    printf("check dot:\n");   // !!!!追加!!!!
    print_mat(D, 1, ret);

    // Check copy
    double ret2[D][1];
    copy(D, 1, ret, ret2);  // ret2 = ret
    printf("check copy:\n");   // !!!!追加!!!!
    print_mat(D, 1, ret2);

    // Check transpose
    double ret_t[1][D];
    transpose(D, 1, ret, ret_t);  // ret_t = ret^T
    printf("check transpose:\n");   // !!!!追加!!!!
    print_mat(1, D, ret_t);

}
