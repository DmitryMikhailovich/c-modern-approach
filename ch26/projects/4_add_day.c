#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void) {
    int month, day, year, n;
    struct tm *dtm = malloc(sizeof(struct tm));

    if (dtm == NULL) {
        printf("Failed to allocate memory for date\n");
        exit(EXIT_FAILURE);
    }

    printf("Enter date (MM/DD/YYYY): ");
    scanf("%2d/%2d/%4d", &month, &day, &year);
    dtm->tm_year = year - 1900;
    dtm->tm_mon = month - 1;
    dtm->tm_mday = day;

    printf("Enter n (number of days): ");
    scanf("%d", &n);
    dtm->tm_mday = dtm->tm_mday + n;

    mktime(dtm);

    printf("Your date %+d days: %02d/%02d/%4d\n", n, dtm->tm_mon + 1, dtm->tm_mday, dtm->tm_year + 1900);

    return 0;
}
