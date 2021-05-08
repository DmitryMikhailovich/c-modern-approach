#include <stdio.h>
#include <stdlib.h>
#include <time.h>

time_t first_midnight(int year);

int main(void) {

    int year;
    time_t timer;
    year = 2000;
    timer = first_midnight(year);
    printf("First midnight of year %d: %s\n", year, ctime(&timer));

    year = 2020;
    timer = first_midnight(year);
    printf("First midnight of year %d: %s\n", year, ctime(&timer));

    return 0;
}

time_t first_midnight(int year) {
    struct tm *dtm = malloc(sizeof(struct tm));
    dtm->tm_year = year - 1900;
    dtm->tm_mon = 0;
    dtm->tm_mday = 1;
    dtm->tm_hour = 0;
    dtm->tm_min = 0;
    dtm->tm_sec = 0;

    return mktime(dtm);
}
