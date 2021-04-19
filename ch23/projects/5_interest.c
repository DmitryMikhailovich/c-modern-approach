#include <stdio.h>
#include <math.h>

double calc_money_on_deposit(double orig_amount, double rate, int years);

int main(void) {
    double orig_amount, rate;
    int years;

    printf("Savings account calculator\n");
    printf("Enter original amount deposited, $: ");
    scanf("%lf", &orig_amount);
    printf("Enter interest rate, %: ");
    scanf("%lf", &rate);
    printf("Enter number of years: ");
    scanf("%d", &years);

    printf("The amount on deposit after %d years at %%%.0f interest would be $%.2f\n",
        years, rate, calc_money_on_deposit(orig_amount, rate, years));
    
    return 0;
} 

double calc_money_on_deposit(double orig_amount, double rate, int years) {
    return orig_amount * exp(rate / 100.0 * years);
}
