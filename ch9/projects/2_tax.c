#include <stdio.h>

float calculate_tax(float income);

int main(void)
{
    float income, tax;
    printf("Enter amount of taxable income in dollars: ");
    scanf("%f", &income);
    tax = calculate_tax(income); 
   printf("Tax due is $%.2f\n", tax);
    return 0;
}
    
float calculate_tax(float income) {
    if (income < 750.0f)
        return 0.01f * income;
    else if (income < 2250.0f)
        return 7.5f + 0.02f * (income - 750.0f);
    else if (income < 3750.0f)
        return 37.5f + 0.03f * (income - 2250.0f);
    else if (income < 5250.0f)
        return 82.5f + 0.04f * (income - 3750.0f);
    else if (income < 7000.0f)
        return 142.5f + 0.05f * (income - 5250.0f);
    else 
        return 230.0f + 0.06f * (income - 7000.0f);
} 
