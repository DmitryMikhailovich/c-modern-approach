#include <stdio.h>

int main(void)
{
  float balance, amount, rate, payment;
  
  printf("Enter amount of loan: ");
  scanf("%f", &amount);
  printf("Enter interest rate: ");
  scanf("%f", &rate);
  printf("Enter monthly payment: ");
  scanf("%f", &payment);
  
  balance = amount;
  balance = balance - payment + balance * rate / 100.0f / 12.0f;
  printf("Balance remaining after first payment: $%.2f\n", balance);
  balance = balance - payment + balance * rate / 100.0f / 12.0f;
  printf("Balance remaining after second payment: $%.2f\n", balance);
  balance = balance - payment + balance * rate / 100.0f / 12.0f;
  printf("Balance remaining after third payment: $%.2f\n", balance);
}
