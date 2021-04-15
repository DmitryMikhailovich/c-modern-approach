#include <stdio.h>

int main(void)
{
    long double i, n, result = 1;
    printf("Enter a positive integer: ");
    scanf("%llf", &n);
    for(i = 2; i <= n; i++) {
        result *= i;
    }
    printf("Factorial of %llf: %llf\n", n, result);
    return 0;
}
