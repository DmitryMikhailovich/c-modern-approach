#include <stdio.h>

int main(void)
{
    float commission, value;
    printf("Enter value of trade: ");
    scanf("%f", &value);

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
    printf("Comission: $%.2f\n", commission);
    return 0;
}
