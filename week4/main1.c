#include <stdio.h>
#include <stdlib.h>

void find_two_largest(int a[], int n, int *largest, int *second_largest) {
  int largest_temp = -1;
  int second_largest_temp = -1;
  for(int *p = &a[0]; p < &a[n]; ++p){
    if(*p > largest_temp){
      second_largest_temp = largest_temp;
      largest_temp = *p;
    } else if (*p > second_largest_temp && *p < largest_temp){
      second_largest_temp = *p;
    }
  }
  if(largest_temp == second_largest_temp){
    second_largest_temp = -1;
  }
  *largest = largest_temp;
  *second_largest = second_largest_temp;
  // この関数を編集してください。必要に応じて別の関数を作って使ってもOKです🥺
}

int main(int argc, char *argv[]) {
    // main関数は編集しないでください

    /*
      $ gcc main1.c -o main1
      $ ./main1 12 3 55
      とすると、
      int vals[] = {12, 3, 55};
      int N = 3;
      のように、valsとNに値がセットされます。
    */

    int N = argc - 1;
    if (N < 2) { 
        printf("Error. please put at least two inputs. For example, ./a.out 34 8\n");
        return -1;
    }

    int vals[N];
    for (int i = 0; i < N; ++i) {
        vals[i] = atoi(argv[i + 1]);
    }

    // 最初はダミーとして-100が入っています
    int big1 = -100;
    int big2 = -100;   
    find_two_largest(vals, N, &big1, &big2);
    printf("largest: %d\n", big1);
    printf("second_largest: %d\n", big2);
}
