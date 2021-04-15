#include <stdio.h>

int main(void)
{
    int num, digit;
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("Reverse of %d is ");
    do {
        digit = num % 10;
        printf("%d", digit);
        num /= 10;
    } while (num != 0);
    printf("\n");
    return 0;
} 
