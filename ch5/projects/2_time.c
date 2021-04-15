#include <stdio.h>

int main(void)
{
    int hours, minutes, hours12;
    printf("Enter a 24-hour time: ");
    scanf("%2d : %2d", &hours, &minutes);
    if (hours > 12)
        hours12 = hours - 12;
    else 
        hours12 = hours;
    printf("Equivalent 12-hour time: %d:%d ", hours12, minutes);
    if (hours > 12)
        printf("PM\n");
    else
        printf("AM\n");
    
    return 0;
}
    
