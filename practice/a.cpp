#include <stdio.h>
int add(int a, int b);
int sub(int a, int b);
int mul(int a, int b);
double div(double a, double b);

int main()
{
    int addv = add(10,20);
    int subv = sub(30,5);
    int mulv = mul(3,2);
    double divv = div(50, 4);

    printf("add func value = %d \n", addv);
    printf("sub func value = %d \n", subv);
    printf("mul func value = %d \n", mulv);
    printf("div func value = %1.2f \n", divv);
    return 0;
}
