#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>


int roll_dice(void);
bool play_game(void);

int main(void)
{
    char ch;
    int wins = 0, losses = 0;
    for(;;) {
        if(play_game()) {
            printf("You win!\n");
            wins++;
        } else {
            printf("You lose!\n");
            losses++;
        }
        printf("\nPlay again? ");
        for(;;) {
            ch = tolower(getchar());
            if(ch == 'y' || ch == 'n')
                break;
        }
        if(ch == 'n')
            break;        
    }
    printf("Wins: %d  Losses: %d\n", wins, losses);
    return 0;
}

bool play_game(void)
{
    int roll = 1, sum, point;
    printf("\n");
    for(;;) {
        sum = roll_dice();
        printf("You rolled: %d\n", sum);
        if(roll == 1 && (sum == 7 || sum == 11)) 
            return true;
        if(roll == 1) {
            point = sum;
            printf("Your point is %d\n", point);
        } else if(sum == point) 
            return true;
          else if(sum == 7)
            return false;
        roll++; 
    }
}

int roll_dice(void)
{
    int dice1, dice2;
    srand(rand() + (unsigned int) time(NULL));
    dice1 = 1 + rand() % 6;
    dice2 = 1 + rand() % 6; 
    return dice1 + dice2;
}
