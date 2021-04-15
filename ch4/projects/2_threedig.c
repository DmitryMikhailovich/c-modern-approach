#include <stdio.h>

int main(void)
{
    int number;
    printf("Enter a three-digit number: ");
    scanf("%3d", &number);
    printf("The reverse is: %d%d%d\n", number % 10, number % 100 / 10, number / 100);
    return 0;
}
