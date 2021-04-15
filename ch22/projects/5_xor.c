#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define KEY '&'

int main(int argc, char *argv[]) {
    FILE *fpi, *fpo;
    int orig_char, new_char;
    if(argc != 3) {
        fprintf(stderr, "Usage: %s input output\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if((fpi = fopen(argv[1], "rb")) != NULL && (fpo = fopen(argv[2], "wb")) != NULL) {

        while((orig_char = fgetc(fpi)) != EOF) {
            new_char = orig_char ^ KEY;
            fputc( new_char, fpo);
        }
        fclose(fpi);
        fclose(fpo);
    } else {
        fprintf(stderr, "Failed to open one of the files\n");
        exit(EXIT_FAILURE);
    }


    return 0;
}

