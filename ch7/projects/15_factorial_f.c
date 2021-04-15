#include <stdio.h>

int main(void)
{
    double i, n, result = 1;
    printf("Enter a positive integer: ");
    scanf("%lf", &n);
    for(i = 2; i <= n; i++) {
        result *= i;
    }
    printf("Factorial of %lf: %lf\n", n, result);
    return 0;
}
