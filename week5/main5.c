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
  double temp = 0;
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

    // ここで、xを初期ベクトルとしてA * x を繰り返すことで、べき乗法を実行してください。
    // それにより、Aの最大固有値を出力してください。
    int k = 4;
    
    double y_k[D][1];
    double y_k_1[D][1];
    double A_to_k[D][D];
    double A_to_k_1[D][D];
    copy(D,D,A,A_to_k);
    copy(D,D,A,A_to_k_1);
    for(int i = 1; i < k; ++i){
      dot(D,D,D,A,A_to_k,A_to_k);
    }
    for(int i = 1; i < k - 1; ++i){
      dot(D,D,D,A,A_to_k_1,A_to_k_1);
    }
    print_mat(D,D,A_to_k);
    print_mat(D,D,A_to_k_1);
    dot(D,D,1,A_to_k,x,y_k);
    dot(D,D,1,A_to_k_1,x,y_k_1);
    print_mat(D,1,y_k);
    print_mat(D,1,y_k_1);
    double lambda;
    
    double y_kT[1][D];
    transpose(D,1,y_k,y_kT);
    
    double bunshi[1][1];
    double bunbo[1][1];

    dot(1,D,1,y_kT,y_k,bunshi);
    dot(1,D,1,y_kT,y_k_1,bunbo);
    
    lambda = bunshi[0][0]/bunbo[0][0];
    
    printf("%.2f\n",lambda);
    printf("%.2f\n",bunshi[0][0]);
    printf("%.2f\n",bunbo[0][0]);
    
}
