#include <stdio.h>

float calc_poly(float x);

int main(void)
{
    float x;
    printf("Enter the value of  x: ");
    scanf("%f", &x);
    
    printf("The result is %f\n", calc_poly(x));
    return 0;
}

float calc_poly(float x)
{
    return 5.0f * x*x*x*x*x + 
        2.0f * x*x*x*x - 
        5.0f * x*x*x -
        x*x + 7.0f * x - 6.0f;
}
