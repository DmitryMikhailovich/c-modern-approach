#include <stdio.h>

void find_closest_flight(int desired_time, int *departure_time, int *arrival_time);

int main(void)
{
    int hours, minutes, ts, departure_time, arrival_time, dephour, depminute, arrhour, arrminute;
    printf("Enter a 24-hour time: ");
    scanf("%d : %d", &hours, &minutes);

    ts = hours * 60 + minutes;
    find_closest_flight(ts, &departure_time, &arrival_time);
    dephour = departure_time / 60;
    depminute = departure_time % 60;
    arrhour = arrival_time / 60;
    arrminute = arrival_time % 60;
     
    printf("Closes departure time is %2d:%02d ", dephour > 12 ? dephour % 12 : dephour, depminute);
    if (dephour > 12)
        printf("p.m.");
    else
        printf("a.m.");
    printf(", arriving at %2d:%02d ", arrhour > 12 ? arrhour % 12 : arrhour, arrminute);
    if (arrhour > 12)
        printf("p.m.");
    else
        printf("a.m."); 
    printf("\n");
    return 0;
}

void find_closest_flight(int desired_time, int *departure_time, int *arrival_time)
{

    if (desired_time >= 21 * 60 + 25) {
        *departure_time = 21 * 60 + 45; *arrival_time = 23 * 60 + 58;
    } else if (desired_time >= 19 * 60 + 0) {
        *departure_time = 19 * 60 + 0; *arrival_time = 21 * 60 + 20;
    } else if (desired_time >= 15 * 60 + 45) {
        *departure_time = 15 * 60 + 45; *arrival_time = 17 * 60 + 55;
    } else if (desired_time >= 14 * 60 + 0) {
        *departure_time = 14 * 60 + 0; *arrival_time = 16 * 60 + 8;
    } else if (desired_time >= 12 * 60 + 47) {
        *departure_time = 12 * 60 + 47; *arrival_time = 15 * 60 + 0;
    } else if (desired_time >= 11 * 60 + 19) {
        *departure_time = 11 * 60 + 19; *arrival_time = 13 * 60 + 31;
    } else if (desired_time >= 9 * 60 + 43) {
        *departure_time = 9 * 60 + 43; *arrival_time = 11 * 60 + 52;
    } else {
        *departure_time = 8 * 60 + 0; *arrival_time = 10 * 60 + 16;
    }
}
