#include <stdio.h>

int main(void)
{
    int m, n, rem, gcd;
    printf("Enter two integers: ");
    scanf("%d %d", &m, &n);
    for(;;) {
        if (n == 0) {
            gcd = m;
            break;
        }
        rem = m % n;
        m = n;
        n = rem;
    }
    printf("Greatest common divisor: %d\n", gcd);
    return 0;
} 
