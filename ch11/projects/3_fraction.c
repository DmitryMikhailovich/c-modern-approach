#include <stdio.h>

void reduce(int numerator, int denominator, int *reduced_numerator, int *reduced_denominator);

int main(void)
{
    int numerator, denominator, n, m, rem, gcd;
    printf("Enter a fraction: ");
    scanf("%d / %d", &numerator, &denominator);
    reduce(numerator, denominator, &numerator, &denominator);
    printf("In lower  terms: %d/%d\n", numerator, denominator);
    return 0;
}

void reduce(int numerator, int denominator, int *reduced_numerator, int *reduced_denominator)
{
    int n, m, gcd, rem;
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
    *reduced_numerator = numerator / gcd;
    *reduced_denominator = denominator / gcd;

}
