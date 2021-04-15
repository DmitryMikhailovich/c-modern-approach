#include <stdio.h>


char *my_fgets(char * restrict s, int n, FILE * restrict stream);
int fputs(const char * restrict s, FILE * restrict stream);

int main(void) {
    return 0;
}

char *my_fgets(char * restrict s, int n, FILE * restrict stream) {
    int i = 0;
    int ch;
    while((ch = fgetc(stream)) != EOF && i < n)
        s[i++] = ch;
    if(feof(stream) || ferror(stream))
        return NULL;

    s[i] = '\0';

    return s;
}

int fputs(const char * restrict s, FILE * restrict stream) {
    int i = 0;
    int ch;
    while((ch = s[i++]) != '\0')
        fputc(ch, stream);
    if(ferror(stream))
        return EOF;
    return i -1;
}
