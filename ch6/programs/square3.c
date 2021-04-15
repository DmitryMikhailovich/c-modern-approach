#include <stdio.h>

int main(void)
{
    int i, num, odd, square;
    printf("This program prints a table of squares.\n");
    printf("Enter number of entries in table: ");
    scanf("%d", &num);
    
    i = 1;
    odd = 3;
    for (square = 1; i <= num ; odd += 2) {
        printf("%10d%10d\n", i, square);
        ++i;
        square += odd;
    }
    return 0;
} 
