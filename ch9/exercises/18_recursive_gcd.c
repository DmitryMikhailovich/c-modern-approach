#include <stdio.h>

int gcd_recursive(int m, int n);
int gcd_recursive(int m, int n) {
    if(n == 0)
        return m;
    return gcd_recursive(n, m % n);
}
