#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>


long int hextoi(char *hex);

int main(void) {
    char *s[] = {"abc1", "hello"};
    for(int i = 0; i < 2; i++) {
        printf("hextoi(%s) = %ld\n", s[i], hextoi(s[i]));
    }
    return 0;
}

long int hextoi(char *hex) {
    char *s;
    long int result = -1;
    bool is_valid_hex = true;
    for(int i = 0; i < strlen(hex); i++) {
        if(!isxdigit(hex[i])) {
            is_valid_hex = false;
            break;
        }
    }
    if(is_valid_hex) {
        result = strtoul(hex, &s, 16);
    } 


    return result;
}
