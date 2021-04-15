#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int hours, minutes, ts, dephour, depminute, arrhour, arrminute;
    char ampm;
    printf("Enter a 12-hour time: ");
    scanf("%d : %d %c", &hours, &minutes, &ampm);

    ampm = toupper(ampm);
    if (ampm == 'P') {
        hours += 12;
    }
    ts = hours * 60 + minutes;
    if (ts >= 21 * 60 + 25) {
        dephour = 21; depminute = 45; arrhour = 23; arrminute = 58;
    } else if (ts >= 19 * 60 + 0) {
        dephour = 19; depminute = 0; arrhour = 21; arrminute = 20;
    } else if (ts >= 15 * 60 + 45) {
        dephour = 15; depminute = 45; arrhour = 17; arrminute = 55;
    } else if (ts >= 14 * 60 + 0) {
        dephour = 14; depminute = 0; arrhour = 16; arrminute = 8;
    } else if (ts >= 12 * 60 + 47) {
        dephour = 12; depminute = 47; arrhour = 15; arrminute = 0;
    } else if (ts >= 11 * 60 + 19) {
        dephour = 11; depminute = 19; arrhour = 13; arrminute = 31;
    } else if (ts >= 9 * 60 + 43) {
        dephour = 9; depminute = 43; arrhour = 11; arrminute = 52;
    } else {
        dephour = 8; depminute = 0; arrhour = 10; arrminute = 16;
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
