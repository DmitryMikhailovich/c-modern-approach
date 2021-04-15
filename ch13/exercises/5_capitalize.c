#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

void capitalize_a(char str[]);
void capitalize_b(char str[]);

int main(void)
{
    int n = 50;
    char str[n];
    
    str = "text";
    printf("capitalize_a: ");
    capitalize_a(str);
    puts(str);
    str = "text";
    printf("capitalize_b: ");
    capitalize_b(str);
    puts(str);
    
    return 0;
}

void capitalize_a(char str[]) {
    int i = 0;

    while(str[i]) {
        str[i] = toupper(str[i]);
        i++;
    }
}

void capitalize_b(char str[]) {
    while(*str) {
        *str = toupper(*str);
        str++;
    }
}

