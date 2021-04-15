#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

int read_line(char str[], int n);
void build_index_url(const char *domain, char *index_url);

int main(void)
{
    int n = 50;
    char str[n], index_url[n];

    printf("build_index_url: ");
    read_line(str, n);
    build_index_url(str, index_url);
    puts(index_url);
    
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

void build_index_url(const char *domain, char *index_url) {
    strcpy(index_url, "http://www.");
    strcat(index_url, domain);
    strcat(index_url, "/index.html");
}

