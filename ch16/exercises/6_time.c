#include <stdio.h>

struct time {
    int hours, minutes, seconds;
};

struct time split_time(long total_seconds);

int main(void) {
    struct time t;
    t = split_time(3678);
    printf("hours=%d, minutes=%d, seconds=%d, total_seconds=%d\n", 
        t.hours, t.minutes, t.seconds, 3678); 
    return 0;
}

struct time split_time(long total_seconds) {
    struct time result = {
        total_seconds / 3600,
        (total_seconds / 60) % 60,
        total_seconds % 60
    };
    return result;
} 
