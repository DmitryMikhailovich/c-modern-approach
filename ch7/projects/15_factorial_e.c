#include <stdio.h>

int main(void)
{
    float i, n, result = 1;
    printf("Enter a positive integer: ");
    scanf("%f", &n);
    for(i = 2; i <= n; i++) {
        result *= i;
    }
    printf("Factorial of %f: %f\n", n, result);
    return 0;
}
