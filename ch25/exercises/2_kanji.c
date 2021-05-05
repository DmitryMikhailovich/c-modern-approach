#include <stdio.h>
#include <stdlib.h>

int mbcheck(const char *s);

int main(void) {
    char *strings[] = {
        "\x05\x87\x80\x36\xed\xaa",
        "\x20\xe4\x50\x88\x3f",
        "\xde\xad\xbe\xef",
        "\x8a\x60\x92\x74\x41"};

    for(int i = 0; i < 4; i++) {
        printf("mbcheck(%s) = %d\n", strings[i], mbcheck(strings[i]));
    }

    return 0;
}

int mbcheck(const char *s) {
    int n;
    
    for (mblen(NULL, 0); ; s += n)
        if ((n = mblen(s, MB_CUR_MAX)) <= 0)
            return n;
}

