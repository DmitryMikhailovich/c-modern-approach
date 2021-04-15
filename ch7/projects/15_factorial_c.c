#include <stdio.h>

int main(void)
{
    long int i, n, result = 1;
    printf("Enter a positive integer: ");
    scanf("%ld", &n);
    for(i = 2; i <= n; i++) {
        result *= i;
    }
    printf("Factorial of %ld: %ld\n", n, result);
    return 0;
}
