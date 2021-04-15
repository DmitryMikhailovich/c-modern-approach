#include <stdio.h>

int main(void)
{
    int n, i, fact;
    float e;

    printf("Enter n: ");
    scanf("%d", &n);
    e = 1.0f; 
    fact = 1;
    for( i = 1; i <= n; i++) {
        fact *= i;
        e += 1.0f / fact; 
    }
    printf("Value of e is %f\n", e);
    return 0;
}
