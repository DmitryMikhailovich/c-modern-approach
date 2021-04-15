#include <stdio.h>

int main(void)
{
    short int i, n, result = 1;
    printf("Enter a positive integer: ");
    scanf("%hd", &n);
    for(i = 2; i <= n; i++) {
        result *= i;
    }
    printf("Factorial of %hd: %hd\n", n, result);
    return 0;
}
