#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *fp;
    int ch;

    if(argc < 2) {
        fprintf(stderr, "Usage: %s filename[, filename, [...]]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    for(int i = 1; i < argc; i++) {
        if((fp = fopen(argv[i], "r")) != NULL) {
            while((ch = fgetc(fp)) != EOF)
                putchar(ch);
            fclose(fp);
        } else {
            fprintf(stderr, "Failed to open file %s\n", argv[i]);
        }
    }

    return 0;
}
