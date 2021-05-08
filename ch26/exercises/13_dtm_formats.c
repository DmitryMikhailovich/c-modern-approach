#include <time.h>
#include <stdio.h>

int main(void) {
    time_t current_timer = time(NULL);
    struct tm *current_time = localtime(&current_timer);
    char s[50+1];

    strftime(s, 50, "%Y-%j", current_time); 
    printf("a. %s\n", s);
    
    strftime(s, 50, "%Y-W%V-%u", current_time); 
    printf("b. %s\n", s);

    strftime(s, 50, "%FT%T", current_time); 
    printf("c. %s\n", s);

    return 0;
}

