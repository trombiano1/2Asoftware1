#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void compare_and_flip(char **a, char **b){
  char *temp;
  if(strlen(*a) <  strlen(*b)){
  } else {
    temp = *b;
    *b = *a;
    *a = temp;
    /*    printf("%p\n",a);*/
  }
}

int main (int argc, char *argv[]) {
    // 自由に編集してください
    // stdlibに入っている、qsort関数は使わないでください。
  char *s[argc - 1];
  for(int i = 1; i < argc; ++i){
    s[i] = argv[i];
  }
  for(int i = 1; i < argc - 1; ++i){
    for(int j = 1; j < (argc - i); ++j){
      compare_and_flip(&argv[j],&argv[j+1]);
    }
  }
  for(int i = 1; i < argc; ++i){
    printf("%s ",argv[i]);
  }
  printf("\n");
  return 0;
}
