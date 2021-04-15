#include <stdio.h>

int main(void) 
{
    int amount, leftAmount;
    printf("Enter amount of dollars: ");
    scanf("%d", &amount);
    printf("$20 bills: %d\n", amount / 20);
    leftAmount = amount - 20 * (amount / 20);
    printf("$10 bills: %d\n", leftAmount / 10);
    leftAmount = leftAmount - 10 * (leftAmount / 10);
    printf("$5 bills: %d\n", leftAmount / 5);
    leftAmount = leftAmount - 5 * (leftAmount / 5);
    printf("%1 bills: %d\n", leftAmount);
    return 0;
}
