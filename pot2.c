#include <stdio.h>
#include <math.h>

int main(void){
    double pot, num;

    printf("2^");
    scanf("%lf", &pot);

    num = pow(2, pot);
    printf("%f", num);

    return 0;
}