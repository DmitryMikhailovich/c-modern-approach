#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "15_line.h"
#include "15_word.h"

#define MAX_WORD_LEN 20

int main(int argc, char *argv[]) {
    FILE *fpi, *fpo;
    char *input_file, *output_file;
    char word[MAX_WORD_LEN+2];
    int word_len;

    if(argc != 3) {
        fprintf(stderr, "Usage: %s input_file output_file\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    input_file = argv[1];
    output_file = argv[2];

    if((fpi = fopen(input_file, "r")) != NULL &&
       (fpo = fopen(output_file, "w")) != NULL) {

        clear_line();
        for (;;) {
            read_word(fpi, word, MAX_WORD_LEN+1);
            word_len = strlen(word);

            if(word_len == 0) {
                flush_line(fpo);
                return 0;
            }
            if (word_len > MAX_WORD_LEN)
                word[MAX_WORD_LEN] = '*';
            if(word_len + 1 > space_remaining()) {
                write_line(fpo);
                clear_line();
            }
            add_word(word);
        }
        fclose(fpi);
        fclose(fpo);
    } else {
        fprintf(stderr, "Failed to open one of the files\n");
        exit(EXIT_FAILURE);
    }


}
