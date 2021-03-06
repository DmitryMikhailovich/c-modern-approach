#include <stdio.h>
#include "15_word.h"

int read_char(FILE *fp) {
    int ch = fgetc(fp);
    if(ch == '\n' || ch == '\t')
        return ' ';
    return ch;
}

void read_word(FILE *fp, char *word, int len) {
    int ch, pos = 0;
    while((ch = read_char(fp)) == ' ')
        ;
    while(ch != ' ' && ch != EOF) {
        if(pos < len)
            word[pos++] = ch;
        ch = read_char(fp);
    }
    word[pos] = '\0';
}
