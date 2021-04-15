#include <stdio.h>

long int fact(int n);

long int fact(int n) {
    long int result = 1;
    for(int i = 2; i <=n ;i++)
        result *= i;
    return result;
}
