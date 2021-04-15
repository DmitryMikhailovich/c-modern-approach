#include <stdio.h>
#include <ctype.h>

int main(void) 
{
    char last_name[20];
    char first_initial, ch;
    _Bool last_name_found = 0;
    int i = 0;
    printf("Enter a first and last name: ");
    scanf(" %c", &first_initial);
    first_initial = toupper(first_initial);
    while((ch = getchar()) != '\n') {
        if(last_name_found) { 
            last_name[i++] = ch;
            continue;
        }
        last_name_found = ch == ' ';
    }
    for(int j = 0; j <= i; j++)
        putchar(last_name[j]);
    printf(", %c.\n", first_initial);
    return 0;
}
