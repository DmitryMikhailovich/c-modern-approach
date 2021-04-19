#include <stdio.h>
#include <string.h>

int numchar(const char *s, char ch);

int main(void) {
    char *s;
    char ch;
    
    s = "Abrakadabra";
    ch = 'a';
    printf("Character '%c' occurs %d times in %s\n", ch, numchar(s, ch), s);

    return 0;
}

int numchar(const char *s, char ch) {
    int num = 0;
    const char *s_ptr = s;
    while(1) {
        s_ptr = strchr(s_ptr + (s_ptr == s ? 0 : 1), ch);
        if(s_ptr == NULL)
            break;
        num++;
    }

    return num;
}
