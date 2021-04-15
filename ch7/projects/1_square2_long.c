#include <stdio.h>

int main(void)
{
    long int i, num;
    printf("This program prints a table of squares.\n");
    printf("Enter number of entries in table: ");
    scanf("%ld", &num);
    
    for (i = 1; i <= num ; i++) {
        printf("%10ld%10ld\n", i, i * i);
    }
    return 0;
} 
