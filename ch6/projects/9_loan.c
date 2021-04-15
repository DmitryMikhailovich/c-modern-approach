#include <stdio.h>

int main(void)
{
  int num_of_payments, i;
  float balance, amount, rate, payment;
  
  printf("Enter amount of loan: ");
  scanf("%f", &amount);
  printf("Enter interest rate: ");
  scanf("%f", &rate);
  printf("Enter monthly payment: ");
  scanf("%f", &payment);
  printf("Enter number of payments: ");
  scanf("%d", &num_of_payments);
  
  balance = amount;
  for(i = 1; i <= num_of_payments; i++) {
    balance = balance - payment + balance * rate / 100.0f / 12.0f;
    printf("Balance remaining after  payment %d: $%.2f\n", i, balance);
  }
  return 0;
}
