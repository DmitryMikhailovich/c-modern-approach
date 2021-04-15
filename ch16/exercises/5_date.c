#include <stdio.h>

struct date { int month, day, year; };
int days_in_month[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int day_of_year(struct date d);
int compare_dates(struct date d1, struct date d2);

int main(void) {

    struct date 
    d1 = {4, 3, 1990},
    d2 = {3, 2, 1989};

    printf("day of year: %d\n", day_of_year(d1));
    printf("compare_dates(d1, d2): %d\n", compare_dates(d1, d2));
    return 0;
}


int day_of_year(struct date d) {
    int sum = 0;
    for(int i = 0; i < d.month-1; i++) {
        sum += days_in_month[i];
    }
    sum += d.day;
    return sum;
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
