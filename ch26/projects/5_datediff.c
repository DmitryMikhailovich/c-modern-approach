#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    struct tm *dtm1 = malloc(sizeof(struct tm));
    struct tm *dtm2 = malloc(sizeof(struct tm));
    int month, day, year;

    if(dtm1 == NULL || dtm2 == NULL) {
        printf("Failed to allocate memory for datetime structs\n");
        exit(EXIT_FAILURE);
    }

    printf("Enter first date (mm/dd/yyyy): ");
    scanf("%2d/%2d/%4d", &month, &day, &year);
    dtm1->tm_mon = month - 1;
    dtm1->tm_mday = day;
    dtm1->tm_year = year - 1900;

    printf("Enter second date (mm/dd/yyyy): ");
    scanf("%2d/%2d/%4d", &month, &day, &year);
    dtm2->tm_mon = month - 1;
    dtm2->tm_mday = day;
    dtm2->tm_year = year - 1900;
    
    printf("Difference between two dates is %d days\n",
            (int) difftime(mktime(dtm2), mktime(dtm1)) / (3600 * 24));

    return 0;
}
