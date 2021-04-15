#include <stdio.h>

int main(void)
{
    int i, num, odd, square;
    printf("This program prints a table of squares.\n");
    printf("Enter number of entries in table: ");
    scanf("%d", &num);
    
    odd = 3;
    square = 1;
    for (i = 1; i <= num ; i++) {
        printf("%10d%10d\n", i, square);
        square += odd;
        odd += 2;
    }
    return 0;
} 
