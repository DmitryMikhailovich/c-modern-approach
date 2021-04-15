#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int hour, minute;
    char ampm;
    printf("Enter a 12-hour time: ");
    scanf("%d : %d %c", &hour, &minute, &ampm);
    ampm = toupper(ampm);
    if(ampm == 'P') {
        hour += 12;
    }
    printf("Equivalent 24-hour time: %2d:%02d\n", hour, minute);
    return 0;
}
