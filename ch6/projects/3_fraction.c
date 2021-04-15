#include <stdio.h>

int main(void)
{
    int numerator, denominator, n, m, rem, gcd;
    printf("Enter a fraction: ");
    scanf("%d / %d", &numerator, &denominator);
    n = numerator; m = denominator; 
    for(;;) {
        if (n == 0) {
            gcd = m;
            break;
        }
        rem = m % n;
        m = n;
        n = rem;
    }
    numerator /= gcd;
    denominator /= gcd;
    printf("In lower  terms: %d/%d\n", numerator, denominator);
    return 0;
}
