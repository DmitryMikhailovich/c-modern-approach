#include <stdio.h>
#include <time.h>
#include <string.h>

int main(void) {
    time_t current_time = time(NULL);
    struct tm *current_tm = localtime(&current_time);
    char dtm_str[50+1];
    char time_str[11+1];

    strftime(dtm_str, 50, "%A, %B %e, %Y %I:%M", current_tm);
    current_tm->tm_hour < 12 ? strcat(dtm_str, "a") : strcat(dtm_str, "p");
    printf("a. %s\n", dtm_str);

    strftime(dtm_str, 50, "%a, %e %b %y %H:%M", current_tm);
    printf("b. %s\n", dtm_str);

    strftime(dtm_str, 50, "%m/%d/%y ", current_tm);
    sprintf(time_str, "%2d:%2d:%2d %2s", 
        current_tm->tm_hour == 0 || current_tm->tm_hour == 12 
            ? 12 
            : current_tm->tm_hour % 12, 
        current_tm->tm_min, 
        current_tm->tm_min,
        current_tm->tm_hour < 12 ? "AM" : "PM");
    strcat(dtm_str, time_str);
    printf("c. %s\n", dtm_str);

    return 0;
}
