#include <stdio.h>
#define T 100

double get_median(double a, double b, double c){
  if((a<=b && b<=c) || (c<=b && b<=a)){
    return b;
  } else if((b<=a && a<=c)||(c<=a && a<=b)){
    return a;
  } else if((a<=c && c<=b)||(b<=c && c<=a)){
    return c;
  }
  return 0;
}

void median_filter(const double *x, double *y) {
    // この関数を編集してください。必要に応じて別の関数を作って使ってもOKです
    // 次のコードはダミー。xをyにコピーするだけ。これを消してコーディングを始めて下さい。
    *y = get_median(*x,*x,*(x+1));
    for(int t = 1; t < T-1; ++t) {
      *(y+t) = get_median(*(x+t-1),*(x+t),*(x+t+1));
    }
    *(y+T-1) = get_median(*(x+T-2),*(x+T-1),*(x+T-1));
}

int main() {
    // main関数は編集しないでください

    /*
      $ gcc main2.c -o main2
      $ ./main2 <signal.txt
      とすると、signal[T]中にsignal.txtのデータが読み込まれます。
      そして、それにmedian_filterを適用した結果が出力されます。
      さらに、
      $ ./main2 <signal.txt >smooth_signal.txt
      とすると、medial_filterを適用した結果をsmooth_signal.txtとして書き出せます。
      その際、無駄なものはprintfしないようにしてください。
    */
    double signal[T];
    for (int t = 0; t < T; ++t) {
        scanf("%lf", signal + t);  // printfの兄弟のscanfという関数で値を読み取ります
    }

    double output[T]; // 結果が入る配列
    median_filter(signal, output);

    for (int t = 0; t < T; ++t) {
        printf("%f\n", output[t]);
    }

}
