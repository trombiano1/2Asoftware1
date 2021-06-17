#include <stdio.h>
#include <stdlib.h>

int get_factorial(int n){
    int product=1;
    for(int i=1;i<=n;i++){
      product *= i;
    }
    return product;
}

int main(int argc, char *argv[])
{
    int n = atoi(argv[1]);
    double calculated_e=0;

    for(int i=0;i<=n;i++){
      calculated_e += 1.0/get_factorial(i);
    }

    printf("%lf\n",calculated_e);

}
