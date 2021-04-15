#include <stdio.h>

struct date {
    int year, month, day;
};

int compare_dates(struct date d1, struct date d2);

int main(void)
{
    struct date d1, d2;
    int y1_full, y2_full, compare_result;
    printf("Enter first date (mm/dd/yy): ");
    scanf("%2d / %2d / %2d", &d1.month, &d1.day, &d1.year);
    printf("Enter second date (mm/dd/yy): ");
    scanf("%2d / %2d / %2d", &d2.month, &d2.day, &d2.year);
    if (d1.year > 50) 
        y1_full = 1900;
    else
        y1_full = 2000;
    y1_full += d1.year;
    if (d2.year > 50)
        y2_full = 1900;
    else
        y2_full = 2000;
    y2_full += d2.year;
 
    compare_result = compare_dates(d1, d2);
 
    if(compare_result <= 0) 
        printf("%d/%d/%02d", d1.month, d1.day, d1.year);
    else
        printf("%d/%d/%02d", d2.month, d2.day, d2.year);
    printf(" is earlier than ");
    
    if(compare_result <= 0) 
        printf("%d/%d/%02d", d2.month, d2.day, d2.year); 
    else
        printf("%d/%d/%02d", d1.month, d1.day, d1.year);
    printf("\n");
    return 0;
} 
    
int compare_dates(struct date d1, struct date d2) {
    if(d1.year < d2.year)
        return -1;
    else if(d1.year > d2.year)
        return 1;
    else if(d1.month < d2.month)
        return -1;
    else if(d1.month > d2.month)
        return 1;
    else if(d1.day < d2.day)
        return -1;
    else if(d1.day > d2.day)
        return 1;
    else
        return 0;
}
