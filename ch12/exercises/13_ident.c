#include <stdio.h>

void init_ident(int *matrix, int n);

void init_ident(int *matrix, int n)
{
    int zeroes = n;
    for (int *p = matrix; p < matrix + n*n; p++) {
        if(zeroes == n)
            zeroes = 0;
        if(zeroes == n) {
            *p = 1;
            zeroes = 0;
        }
        else { 
            *p = 0;
            zeroes++;
        }
    }
}   
