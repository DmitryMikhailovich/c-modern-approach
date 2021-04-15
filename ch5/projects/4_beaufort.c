#include <stdio.h>

int main(void)
{
    int speed;
    printf("Enter wind speed in knots: ");
    scanf("%d", &speed);
    if (speed < 1)
        printf("It's calm");
    else if (speed < 4)
        printf("It's light air");
    else if (speed < 28)
        printf("It's breeze");
    else if (speed < 48)
        printf("It's gale");
    else if (speed < 64)
        printf("It's storm");
    else
        printf("It's hurricane!");
    printf("\n");
    return 0;
}
