#include <stdio.h>

#define ARR_LENGTH ((int) sizeof(times) / sizeof(times[0]))

struct time {
    int departure, arrival;
};

int main(void)
{
    struct time times[] = {
    {21*60+45, 23*60+58},
    {19*60, 21*60+20},
    {15*60+45, 17*60+55},
    {14*60, 16*60+8},
    {12*60+47, 15*60},
    {11*60+19, 13*60+31},
    {9*60+43, 11*60+52},
    {8*60, 10*60+16}
    };
    int hours, minutes, ts, dephour, depminute, arrhour, arrminute;
    printf("Enter a 24-hour time: ");
    scanf("%d : %d", &hours, &minutes);
    
    ts = hours * 60 + minutes;
    for(int i = 0; i < ARR_LENGTH; i++) {
        if(ts >= times[i].departure || i == ARR_LENGTH - 1) {
            dephour = times[i].departure / 60;
            depminute = times[i].departure % 60;
            arrhour = times[i].arrival / 60;
            arrminute = times[i].arrival % 60;
            break;
        }
    }
     
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
