#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

int read_line(char str[], int n);
void get_extension(const char *file_name, char *extension);

int main(void)
{
    int n = 50;
    char str[n], ext[n];


    printf("get_extension: ");
    read_line(str, n);
    get_extension(str, ext);
    puts(ext);

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


void get_extension(const char *file_name, char *extension)
{
    const char *c = file_name + strlen(file_name);
    while(c > file_name)
        if(*c == '.')
            break;
        else
            c--;
    if(c == file_name)
        strcpy(extension, "");
    else
        strcpy(extension, c+1);

}

