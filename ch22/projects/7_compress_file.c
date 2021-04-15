#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[]) {
    FILE *fpi, *fpo;
    int ch, prev_ch = EOF;
    int count = 1;

    if(argc != 2) {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char output_file[strlen(argv[1]) + 5];
    strcpy(output_file, argv[1]);
    strncat(output_file, ".rle", 5);
    if((fpi = fopen(argv[1], "rb")) != NULL && (fpo = fopen(output_file, "wb")) != NULL) {
        while((ch = fgetc(fpi)) != EOF) {
            if(prev_ch == EOF) {
                prev_ch = ch;
                continue;
            }
            if(prev_ch == ch) {
                count++;
            } else {
                fputc(count, fpo);
                fputc(prev_ch, fpo);
                count = 1;
            }
            prev_ch = ch;

        }
        fputc(count, fpo);
        fputc(prev_ch, fpo);
        
        fclose(fpi);
        fclose(fpo);
    } else {
        fprintf(stderr, "Failed to open files\n");
        exit(EXIT_FAILURE);
    }

    return 0;

}
