#include <stdio.h>

int main(void)
{
    int hours, minutes, ts, dephour, depminute, arrhour, arrminute;
    int deptimes[8][2] = {{21, 45}, {19, 0}, {15, 45}, {14, 0}, 
                          {12, 47}, {11, 19}, {9, 43}, {8, 0}}, 
        arrtimes[8][2] = {{23, 58}, {21, 20}, {17, 55}, {16, 8},
                          {15, 0}, {13, 31}, {11, 52}, {10, 16}};
    printf("Enter a 24-hour time: ");
    scanf("%d : %d", &hours, &minutes);

    ts = hours * 60 + minutes;
    for(int i = 0; i < sizeof(deptimes); i++) {
        dephour = deptimes[i][0], depminute = deptimes[i][1];
        if(ts >= dephour * 60 + depminute) {
            arrhour = arrtimes[i][0], arrminute = arrtimes[i][1];
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
