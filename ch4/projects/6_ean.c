#include <stdio.h>

int main(void) 
{
    int  first, second, i1, i2, i3, i4, i5, i6, j1, j2, j3, j4, j5, j6,
        first_sum, second_sum, total;
    printf("Enter the first 12 digits of a EAN: "); 
    scanf("%6d%6d",  &first, &second);
    i1 = first / 100000;
    i2 = (first %= 100000) / 10000;
    i3 = (first %= 10000) / 1000;
    i4 = (first %= 1000) / 100;
    i5 = (first %= 100) / 10;
    i6 = (first % 10);

    j1 = second / 100000;
    j2 = (second %= 100000) / 10000;
    j3 = (second %= 10000) / 1000;
    j4 = (second %= 1000) / 100;
    j5 = (second %= 100) / 10;
    j6 = (second % 10);
    first_sum =  i2 + i4 + i6 + j2 + j4 + j6;
    second_sum = i1 + i3 + i5 + j1 + j3 + j5;
    total = 3 * first_sum + second_sum;
    printf("Check digit: %d\n", 9 - ((total - 1) % 10));
    return 0;
}
