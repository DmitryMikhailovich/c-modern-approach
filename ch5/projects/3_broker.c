#include <stdio.h>

int main(void)
{
    float commission, shares, price, value;
    printf("Enter number of shares: ");
    scanf("%f", &shares);
    printf("Enter price of a share: ");
    scanf("%f", &price);
    value = price * shares;
    
    if(value < 2500.00f) 
        commission = 30.0f + .017f * value;
    else if (value < 6250.0f)
        commission = 56.0f + 0.0066f * value;
    else if (value < 20000.0f)
        commission = 76.0f + .0034f * value;
    else if (value < 50000.0f)
        commission = 100.00f + .0022f * value;
    else if (value < 500000.00f)
        commission = 155.00f + .0011f * value;
    else
        commission = 255.00f + .0009f * value;
    
    if (commission < 39.00f)
        commission = 39.00f;
    printf("Commission: $%.2f\n", commission);
    if (shares < 2000) 
        commission = 33.0f + 0.03f * shares;
    else 
        commission = 33.0f + 0.02f * shares;
    
    printf("Rival's commission: $%.2f\n", commission);
    return 0;
}
