#include <stdio.h>

int main(void)
{
    float income, tax;
    printf("Enter amount of taxable income in dollars: ");
    scanf("%f", &income);
    
    if (income < 750.0f)
        tax = 0.01f * income;
    else if (income < 2250.0f)
        tax = 7.5f + 0.02f * (income - 750.0f);
    else if (income < 3750.0f)
        tax = 37.5f + 0.03f * (income - 2250.0f);
    else if (income < 5250.0f)
        tax = 82.5f + 0.04f * (income - 3750.0f);
    else if (income < 7000.0f)
        tax = 142.5f + 0.05f * (income - 5250.0f);
    else 
        tax = 230.0f + 0.06f * (income - 7000.0f);
    printf("Tax due is $%.2f\n", tax);
    return 0;
}
    
