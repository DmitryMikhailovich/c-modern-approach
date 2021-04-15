#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

int read_line_4a(char str[], int n);
int read_line_4b(char str[], int n);
int read_line_4c(char str[], int n);
int read_line_4d(char str[], int n);

int main(void)
{
    int n = 50;
    char str[n];

     printf("read_line_4a: ");
     read_line_4a(str, n);
     puts(str);
     printf("read_line_4b: ");
     read_line_4b(str, n);
     puts(str);
     printf("read_line_4c: ");
     read_line_4c(str, n);
     puts(str);
     printf("read_line_4d: ");
     read_line_4d(str, n);
     puts(str);
    
    return 0;
}

int read_line_4a(char str[], int n)
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

int read_line_4b(char str[], int n)
{
    int ch, i = 0;
    while(!isspace(ch = getchar()) )
        if(i < n)
            str[i++] = ch;
    str[i] = '\0';
    return i;
}

int read_line_4c(char str[], int n)
{
    int ch, i = 0;
    while((ch = getchar()) != '\n' )
        if(i < n - 1)
            str[i++] = ch;
    str[i] = '\n';
    str[i+1] = '\0';
    return i;
}

int read_line_4d(char str[], int n)
{
    int ch, i = 0;
    while((ch = getchar()) != '\n')
        if(i < n)
            str[i++] = ch;
    str[i] = '\0';
    return i;
}

