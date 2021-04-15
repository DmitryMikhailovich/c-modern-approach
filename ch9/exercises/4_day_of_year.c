#include <stdio.h>

int day_of_year(int month, int day, int year);


int day_of_year(int month, int day, int year)
{
    int result = 0;
    int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
        days_in_month[1] = 29;
    for(int i = 0; i <= month - 2; i++)
        result += days_in_month[i];
    return result + day;
}

