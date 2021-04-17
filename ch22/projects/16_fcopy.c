#include <stdio.h>
#include <stdlib.h>

#define BLOCK_SIZE 512

int main(int argc, char *argv[]) {
    FILE *source_fp, *dest_fp;
    int blk[BLOCK_SIZE];
    int count;

    if (argc != 3) {
        fprintf(stderr, "usage: fcopy source dest\n");
        exit(EXIT_FAILURE);
    }

    if((source_fp = fopen(argv[1], "rb")) == NULL) {
        fprintf(stderr, "Can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    if((dest_fp = fopen(argv[2], "wb")) == NULL) {
        fprintf(stderr, "Can't open %s\n", argv[2]);
        fclose(source_fp);
        exit(EXIT_FAILURE);
    }

    while(1) {
        if(feof(source_fp)) {
            break;
        }
        count = fread(blk, sizeof(int), BLOCK_SIZE, source_fp);
        fwrite(blk, sizeof(int), count, dest_fp);
        if(ferror(dest_fp)) {
            printf("Failed to write block\n");
            exit(EXIT_FAILURE);
        }
    }

    fclose(source_fp);
    fclose(dest_fp);
    return 0;
}
