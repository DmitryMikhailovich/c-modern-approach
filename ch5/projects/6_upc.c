#include <stdio.h>

int main(void) 
{
    int  d, first, second, i1, i2, i3, i4, i5, j1, j2, j3, j4, j5,
        control, first_sum, second_sum, total;
    printf("Enter the UPC: "); 
    scanf("%1d%5d%5d%1d", &d, &first, &second, &control);
    i1 = first / 10000;
    i2 = (first %= 10000) / 1000;
    i3 = (first %= 1000) / 100;
    i4 = (first %= 100) / 10;
    i5 = first % 10;

    j1 = second / 10000;
    j2 = (second %= 10000) / 1000;
    j3 = (second %= 1000) / 100;
    j4 = (second %= 100) / 10;
    j5 = (second % 10);
    first_sum = d + i2 + i4 + j1 + j3 + j5;
    second_sum = i1 + i3 + i5 + j2 + j4;
    total = 3 * first_sum + second_sum;
    if (control == 9 - ((total - 1) % 10))
        printf("VALID\n");
    else
        printf("NOT VALID\n");
    return 0;
}
