#include <stdio.h>

int main(void)
{
    int i, fact;
    float e, e_prev, eps;

    printf("Enter epsilon: ");
    scanf("%f", &eps);
    e = 1.0f; 
    fact = 1;
    i = 1;
    do { 
        e_prev = e;
        fact *= i++;
        e += 1.0f / fact; 
    } while (e - e_prev >= eps);
    printf("Value of e is %f\n", e);
    return 0;
}
