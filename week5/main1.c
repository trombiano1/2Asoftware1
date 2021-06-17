#include <stdio.h>
#include <stdlib.h>

void compare_and_flip(int *a, int *b){
  int temp;
  if(*a <  *b){
  } else {
    temp = *b;
    *b = *a;
    *a = temp;
  }
}

int main (int argc, char *argv[]) {
  int nums[argc - 1];
  int *nums_p = nums;
  for (int i = 1; i < argc; ++i){
    nums[i - 1] = atoi(argv[i]);
  }
  for(int i = 0; i < argc - 2; ++i){
    for(int j = 0; j < (argc - i - 2); ++j){
      compare_and_flip(nums_p+j,nums_p+j+1);
    }
  }
  for(int i = 0; i < argc - 1; ++i){
    printf("%d\n",nums[i]);
  }
}
