#include <stdio.h>
#include <ctype.h>

int main(void) 
{
    char first_initial, ch;
    _Bool last_name_found = 0;
    printf("Enter a first and last name: ");
    scanf(" %c", &first_initial);
    first_initial = toupper(first_initial);
    while((ch = getchar()) != '\n') {
        if(last_name_found) { 
            putchar(ch);
            continue;
        }
        last_name_found = ch == ' ';
    }
    printf(", %c.\n", first_initial);
    return 0;
}
