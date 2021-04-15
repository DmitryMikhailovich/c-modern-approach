#include <stdio.h>

int main(void)
{
    int day, month, year, min_day, min_month, min_year;
    min_day = 31; min_month = 12; min_year = 99;
    for(;;) {
            printf("Enter a date (mm/dd/yy): ");
            scanf("%2d / %2d / %2d", &month, &day, &year);
            if (year == 0 && month == 0 && day == 0) {
                break;
            }
            if ( year * 10000 + month * 100 + day < min_year * 10000 + min_month * 100 + min_day) {
                min_day = day;
                min_month = month;
                min_year = year;
            }
    } 
    printf("%d/%d/%02d is the earliest date\n", min_month, min_day, min_year);
    
    return 0;
} 
