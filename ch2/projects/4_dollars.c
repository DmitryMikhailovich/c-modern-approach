#include <stdio.h>

int main(void) 
{
    float amount, withTax;
    printf("Enter amount of dollars: ");
    scanf("%f", &amount);
    withTax = 1.05f * amount;
    printf("With tax added: $%.2f\n", withTax);
    return 0;
}
