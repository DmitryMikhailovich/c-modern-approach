#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[]) {
    FILE *fpi, *fpo;
    int ch, prev_ch = EOF;
    int count = 0;
    int i;

    if(argc != 2) {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    if(strcmp(argv[1] + strlen(argv[1]) - 4, ".rle") != 0) {
        fprintf(stderr, "Input file should have extension .rle\n");
        exit(EXIT_FAILURE);
    } 
    

    char output_file[strlen(argv[1]) - 4];
    strncpy(output_file, argv[1], strlen(argv[1]) - 4);
    if((fpi = fopen(argv[1], "rb")) != NULL
         && (fpo = fopen(output_file, "wb")) != NULL) {
        while((ch = fgetc(fpi)) != EOF) {
            if(count == 0) {
                count = ch;
            } else {
                for(i = 0; i < count; i++)
                    fputc(ch, fpo);
                count = 0;
            }
        }
        
        fclose(fpi);
        fclose(fpo);
    } else {
        fprintf(stderr, "Failed to open files\n");
        exit(EXIT_FAILURE);
    }

    return 0;

}
