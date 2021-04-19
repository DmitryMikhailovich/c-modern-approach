#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>


int main(void) {
    int ch;
    bool line_text_found = false;
    
    while((ch = getchar()) != EOF) {
        if(!line_text_found && isblank(ch))
            continue;
        else if((ch == '\r' || ch == '\n')) {
            if(line_text_found) 
                putchar(ch);
            if(ch == '\r') {
                ch = getchar();
                if(ch != '\n')
                    ungetc(ch, stdin);
                else if(line_text_found)
                    putchar(ch);
            }
            line_text_found = false;
            continue;
        }
        else
            line_text_found = true;         
        putchar(ch);
    }
    return 0;
}
