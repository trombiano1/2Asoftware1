#include <stdio.h>

typedef struct a {
  int arr[3];
} A;

void print_point(Point pt){
  printf("pt: 

int main() {
  A a1 = {.arr = {1,2,3}};
  A a2 = a1;

  for (int i=0;i<3;++i){
    printf("%d, %d\n", a1.arr[i], a2.arr[i]);
  }

  a2.arr[0] = 100;
  for (int  i = 0; i < 3; ++i){
    printf("%d, %d\n", a1.arr[i], a2.arr[i]);
  }
}
