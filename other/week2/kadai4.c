#include <stdio.h>
#include <math.h>
int is_prime(int); /*引数画素数の場合は１，それ以外の場合は0を返す*/
int main(){
  double product=1.0;
  double calculated_pi;
  int j;
  for(j=2;j<=10000;j++){
    if(is_prime(j)){
      product*=1-(1.0/(j*j));
    }
  }
  calculated_pi = sqrt(6.0/product);
  printf("%f\n",calculated_pi);
}
int is_prime(int n){
  int i;
  for(i=2;i<(int)sqrt(n)+1;i++){
    if(n%i==0){
      return 0;
    }
  }
  return 1;
}

0
