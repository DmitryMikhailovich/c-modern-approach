#include <stdio.h>

int main(void)
{
    int d1, m1, y1, d2, m2, y2, y1_full, y2_full, num_earlier;
    printf("Enter first date (mm/dd/yy): ");
    scanf("%2d / %2d / %2d", &m1, &d1, &y1);
    printf("Enter second date (mm/dd/yy): ");
    scanf("%2d / %2d / %2d", &m2, &d2, &y2);
    if (y1 > 50) 
        y1_full = 1900;
    else
        y1_full = 2000;
    y1_full += y1;
    if (y2 > 50)
        y2_full = 1900;
    else
        y2_full = 2000;
    y2_full += y2;
 
    num_earlier = d1 + 100 * m1 + 10000 * y1_full > d2 + 100 * m2 + 10000 * y2_full ? 2 : 1; 
 
    if(num_earlier == 1) 
        printf("%d/%d/%02d", m1, d1, y1);
    else
        printf("%d/%d/%02d", m2, d2, y2);
    printf(" is earlier than ");
    
    if(num_earlier == 2) 
        printf("%d/%d/%02d", m1, d1, y1);
    else
        printf("%d/%d/%02d", m2, d2, y2);
    printf("\n");
    return 0;
} 
