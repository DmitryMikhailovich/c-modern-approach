#include <stdio.h>

int main(void)
{
    int days, start_day, i; 
    printf("Enter number of days in month: ");
    scanf("%d", &days);
    printf("Enter starting day of the week (1=Sun, 7=Sat): ");
    scanf("%d", &start_day);
    for (i = 1; i < start_day; i++) {
        printf("   ");
    }
    for (i = 1; i <= days; i++) {
        printf("%3d", i);
        if ( (start_day + i) % 7 == 1) {
            printf("\n");
        }
    }
    printf("\n");
    return 0;
}
