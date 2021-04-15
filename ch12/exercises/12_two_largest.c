#include <stdio.h>


void find_two_largest(const int *a, int n, int *largest, int *second_largest);

void find_two_largest(const int *a, int n, int *largest, int *second_largest)
{
    const int *p;
    *largest = *a;
    if(n == 1) {
        *second_largest = *largest;
        return;
    }
    else
        *second_largest = *(a+1);
    for(p = a+2; p <= a+n; p++) {
        if(*p > *largest) {
            *second_largest = *largest;
            *largest = *p;
        }
    }
}
