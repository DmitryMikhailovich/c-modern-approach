#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    FILE *fp;
    int ch;

    if(argc != 2) {
        printf("Usage: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if((fp = fopen(argv[1], "r")) != NULL) {
        while((ch = getc(fp)) != EOF)
            if(isalpha(ch))
                putchar(toupper(ch));
            else
                putchar(ch);
    } else {
        fprintf(stderr, "Failed to open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    return 0;
}

