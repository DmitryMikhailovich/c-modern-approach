#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

int read_line(char str[], int n);
void censor(char str[]);

int main(void)
{
    int n = 50;
    char str[n];

    printf("censor: ");
    read_line(str, n);
    censor(str);
    puts(str);

    return 0;
}

int read_line(char str[], int n)
{
    int ch, i = 0;
    while(isspace(ch = getchar()))
        ; 
    do {
        if(i < n)
            str[i++] = ch;
    } while((ch = getchar()) != '\n');
    str[i] = '\0';
    return i;
}

void censor(char str[]) {
    int i;
    for(i = 0; str[i] != '\0'; i++) {
        if(str[i] == 'f' && str[i+1] == 'o' && str[i+2] == 'o')
            str[i] = str[i+1] = str[i+2] = 'x';
    }
}
