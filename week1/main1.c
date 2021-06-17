#include <stdio.h>
#include <stdlib.h>

/*
  関数は自由に追加してください
*/

int ten_power(int n){
  int return_value = 1;
  for(int i=0;i<n;i++){
    return_value *= 10;
  }
  return return_value;
}

int get_digit(int n){
  for(int i = 1;;i++){
    n /= 10;
    if((int)(n) == 0){
      return i;
    }
  }
}

int kth_digit(int n, int k){
 
  return n;
}

int main(int argc, char *argv[])
{
  int reversed_n = 0;
  /*
      $ gcc main1.c -o main1
      $ ./main1 123
      とすると、nには123が入ります。
  */
  int n = atoi(argv[1]);
    
  /* 注意：itoa関数は使わないでください。 */


    /*
      以下に自由に記述してください
    */
  for(int i=0;i<=get_digit(n);i++){
    reversed_n+=((n - (n/ten_power(i))*ten_power(i))/ten_power(i-1))*ten_power(get_digit(n)-i);
  }
  printf("%d\n",reversed_n);
  return 0;
}
