#include <stdio.h>
#include <string.h>

#define MAX_REMIND 50
#define MSG_LEN 60

int read_line(char str[], int n);

int main(void)
{
    char reminders[MAX_REMIND][MSG_LEN+6];
    char day_hour_str[6], msg_str[MSG_LEN+1];
    int day, hour, i, j, num_remind = 0;
    for(;;) {
        if(num_remind == MAX_REMIND) {
            printf("-- No space left --\n");
            break;
        }
        
        printf("Enter day, hour and reminder: ");
        scanf("%2d", &day);

        if(day < 0 || day > 31) {
            printf("Day should be between 1 and 31 inclusive, or 0 to exit.\n");
            continue;
        }
        if(day == 0)
            break;
 
        scanf("%2d", &hour);
        
        sprintf(day_hour_str, "%2d %2d", day, hour);
        read_line(msg_str, MSG_LEN);
        
        for(i = 0; i < num_remind; i++)
            if(strcmp(day_hour_str, reminders[i]) < 0)
                break; 
        for(j = num_remind; j > i; j--)
            strcpy(reminders[j], reminders[j-1]);
        strcpy(reminders[i], day_hour_str);
        strcat(reminders[i], msg_str);

        num_remind++;
    }

    printf("\nDay Reminder\n");
    for(i = 0; i < num_remind; i++)
        printf(" %s\n", reminders[i]);
    return 0;
}

int read_line(char str[], int n)
{
    int ch, i = 0;
    
    while((ch = getchar()) != '\n')
        if(i < n)
            str[i++] = ch;
    str[i] = '\0';
    return i;
}

