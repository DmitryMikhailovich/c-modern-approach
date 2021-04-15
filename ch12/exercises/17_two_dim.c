#include <stdio.h>

#define LEN 10

int sum_two_dimensional_array(const int *a, int n);

int sum_two_dimensional_array(const int *a, int n)
{
    int sum = 0;
    for(const int *p = a; p < a + n*LEN; p++)
        sum += *p;
    return sum;
}
