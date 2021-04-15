#include <stdio.h>

int main(void)
{
    int num, day, month, year;
    float price;

    printf("Enter item number: ");
    scanf("%d", &num);
    printf("Enter unit price: ");
    scanf("%f", &price);
    printf("enter purchase date (mm/dd/yyyy): ");
    scanf("%d / %d / %d", &month, &day, &year);

    printf("Item\tUnit\tPurchase\n");
    printf("\tPrice\tDate\n");
    printf("%d\t$%7.2f\t%02d/%02d/%04d\n", num, price, month, day, year);

    return 0;
}
