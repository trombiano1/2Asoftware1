x0#include <stdio.h>
#include <math.h>
int gcd(int,int);
int gcd(int a, int b){
  int t;
  while(b != 0){
    t = b;
    b = a%b;
    a = t;
  }
  return a;
}
int main(){
  int x;
  int y;
  int z;
  for(x=1;x<1000;x++){
    for(y=x;y<1000;y++){
      for(z=x;z<1000;z++){
	if(x*x+y*y==z*z){
	  if(gcd(x,y)==1){
	    printf("%d^2+%d^2=%d^2\n",x,y,z);
	  }
	}
      }
    }
  }
}
