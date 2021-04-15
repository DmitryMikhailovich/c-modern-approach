#include <stdio.h>

void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones);

int main(void) 
{
    int amount, twenties, tens, fives, ones;
    printf("Enter amount of dollars: ");
    scanf("%d", &amount);
    pay_amount(amount, &twenties, &tens, &fives, &ones);
    printf("$20 bills: %d\n", twenties);
    printf("$10 bills: %d\n", tens);
    printf("$5 bills: %d\n", fives);
    printf("%1 bills: %d\n", ones);
    return 0;
}


void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones)
{
    int left_dollars;
    *twenties = dollars/20;
    left_dollars = dollars - 20 * (dollars / 20);
    *tens = left_dollars / 10;
    left_dollars = left_dollars - 10 * (left_dollars / 10);
    *fives = left_dollars / 5;
    *ones = left_dollars - 5 * (left_dollars / 5);
}
