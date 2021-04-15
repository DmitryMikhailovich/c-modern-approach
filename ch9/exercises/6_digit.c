#include <stdio.h>

int digit(int n, int k);

int digit(int n, int k)
{
    int result = 0;
    for(int i = 0; i < k; i++) {
        result = n % 10;
        n /= 10;
    }
    return result;
}

int main(void)
{
    int n, k;
    printf("Enter number: ");
    scanf("%d", &n);
    printf("Enter digit number: ");
    scanf("%d", &k);
    printf("The %dth digit of %d is %d\n", k, n, digit(n, k));
}

