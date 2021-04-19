#include <stdio.h>
#include <ctype.h>


int main(void) {

    int ch, prev_ch = EOF;

    while((ch = getchar()) != EOF) {
        if(isalpha(ch) && (isspace(prev_ch) || prev_ch == EOF))
            putchar(toupper(ch));
        else
            putchar(ch);
        prev_ch = ch;
    }

    return 0;
}
