#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *fpi, *fpo;
    int ch;

    if(argc != 3) {
        fprintf(stderr, "Usage: %s inputfile outputfile\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if((fpi = fopen(argv[1], "rb")) == NULL) {
        fprintf(stderr, "Failed to open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    if((fpo = fopen(argv[2], "wb")) == NULL) {
        fclose(fpi);
        fprintf(stderr, "Failed to open %s\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    while((ch = fgetc(fpi)) != EOF) {
        if(ch != '\n') {
            fputc(ch, fpo);
        } else {
            fputc('\r', fpo);
            fputc('\n', fpo);
        }
    }

    fclose(fpi);
    fclose(fpo);

    return 0;
}
