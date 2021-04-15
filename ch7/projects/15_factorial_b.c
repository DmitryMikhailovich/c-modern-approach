#include <stdio.h>

int main(void)
{
    int i, n, result = 1;
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    for(i = 2; i <= n; i++) {
        result *= i;
    }
    printf("Factorial of %d: %d\n", n, result);
    return 0;
}
