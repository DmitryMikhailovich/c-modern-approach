#include <stdio.h>

int num_digits(int n);

int num_digits(int n)
{
    int num_digits = 1;
    while(n > 9) {
        num_digits++;
        n /= 10;
    }
    return num_digits;
}

