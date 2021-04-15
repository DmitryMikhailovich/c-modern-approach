#include <stdio.h>

int main(void)
{
    short int i, num;
    printf("This program prints a table of squares.\n");
    printf("Enter number of entries in table: ");
    scanf("%hd", &num);
    
    for (i = 1; i <= num ; i++) {
        printf("%10hd%10hd\n", i, i * i);
    }
    return 0;
} 
