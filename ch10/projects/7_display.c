#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_DIGITS 10

void clear_digits_array(void);
void process_digit(int digit, int position);
void print_digits_array(void);
int parse_digit(char ch);

const int segments[MAX_DIGITS][7] = {
{1, 1, 1, 1, 1, 1, 0},
{0, 1, 1, 0, 0, 0, 0},
{1, 1, 0, 1, 1, 0, 1},
{1, 1, 1, 1, 0, 0, 1},
{0, 1, 1, 0, 0, 1, 1},
{1, 0, 1, 1, 0, 1, 1},
{1, 0, 1, 1, 1, 1, 1},
{1, 1, 1, 0, 0, 0, 0},
{1, 1, 1, 1, 1, 1, 1}, 
{1, 1, 1, 1, 0, 1, 1}}; 
char digits[4][4*MAX_DIGITS];

int main(void)
{
    int position = 0, digit;
    char ch;
    clear_digits_array();
    printf("Enter a number: ");
    while(position < MAX_DIGITS) {
        ch = getchar();
        if(isdigit(ch)) {
            digit = parse_digit(ch);
            process_digit(digit, position++);
        }
        else if(ch == '\n')
            break;
    }
    print_digits_array();
    return 0;
}
   
int parse_digit(char ch) {
    switch(ch) {
        case '0': return 0;
        case '1': return 1;
        case '2': return 2;
        case '3': return 3;
        case '4': return 4;
        case '5': return 5;
        case '6': return 6;
        case '7': return 7;
        case '8': return 8;
        case '9': return 9;
        default:
            printf("Character %c is not a digit\n", ch);
            exit(EXIT_FAILURE);
    }
} 


void print_digits_array(void) {
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4*MAX_DIGITS; j++) {
            putchar(digits[i][j]);
        }
        putchar('\n');
    }
} 

void clear_digits_array(void) 
{
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4*MAX_DIGITS; j++)
            digits[i][j] = ' ';
}

void process_digit(int digit, int position)
{
    int dseg[7];
    for(int i = 0; i < 7; i++)
        dseg[i] = segments[digit][i];

    digits[1][position*4 + 1] = dseg[0] == 1 ? '_' : ' ';
    digits[2][position*4 + 2] = dseg[1] == 1 ? '|' : ' ';
    digits[3][position*4 + 2] = dseg[2] == 1 ? '|' : ' ';
    digits[3][position*4 + 1] = dseg[3] == 1 ? '_' : ' ';
    digits[3][position*4 + 0] = dseg[4] == 1 ? '|' : ' ';
    digits[2][position*4 + 0] = dseg[5] == 1 ? '|' : ' ';
    digits[2][position*4 + 1] = dseg[6] == 1 ? '_' : ' ';
    
}
