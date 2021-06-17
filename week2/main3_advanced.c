#include <stdio.h>
#include <stdlib.h>

int get_factorial(int n){
    int product=1;
    for(int i=1;i<=n;i++){
      product *= i;
    }
    return product;
}

double calculate_e(int n){
    double calculated_e=0;

    for(int i=0;i<=n;i++){
      calculated_e += 1.0/get_factorial(i);
    }

    return calculated_e;
}

int main(int argc, char *argv[])
{
    double epsilon = atof(argv[1]);
    int n=1;
    
    do{
      n++;
    }while(2.7182818284-calculate_e(n)>epsilon);

    printf("%d\n",n);

}
