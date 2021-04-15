#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


int main(int argc, char *argv[]) {
    FILE *fp;
    int count = 0;
    int ch, prev_ch = EOF;

    if(argc != 2) {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if((fp = fopen(argv[1], "r")) != NULL) {
        while((ch = fgetc(fp)) != EOF) {
            if(isspace(ch) && !isspace(prev_ch))
                count++;
            prev_ch = ch;
        }
        fclose(fp);
        printf("%d\n", count);
    } else {
        fprintf(stderr, "Failed to open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    return 0;
}
