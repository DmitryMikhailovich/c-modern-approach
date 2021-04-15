#include <stdio.h>

int main(void)
{
    long long int i, n, result = 1;
    printf("Enter a positive integer: ");
    scanf("%lld", &n);
    for(i = 2; i <= n; i++) {
        result *= i;
    }
    printf("Factorial of %lld: %lld\n", n, result);
    return 0;
}
