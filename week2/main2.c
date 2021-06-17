#include <stdio.h>
#include <stdlib.h>

char a_or_b(int n){
  if(n%2==0){
    return 'A'; 
  }else{
    return 'B';
  }
}

int main(int argc, char *argv[])
{

    int n = atoi(argv[1]);
    for(int i=0;i<n;i++){
	for(int j=0;j<n;j++){
	  printf("%c",a_or_b(i+j));
	}
	printf("\n");
    }

}
