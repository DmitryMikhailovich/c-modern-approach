#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int letters[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    int value = 0;
    char ch;


    printf("Enter a word: ");
    do {
        ch = toupper(getchar());
        value += letters[ch - 'A']; 
    } while (ch != '\n');
    printf("Scrabble value: %d\n", value);
    return 0;
} 
