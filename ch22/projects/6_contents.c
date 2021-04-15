#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define LINE_SIZE 10

int main(int argc, char *argv[]) {
    FILE *fp;
    int offset = 0;
    int ch;
    char chars[LINE_SIZE+1];

    if(argc != 2) {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if((fp = fopen(argv[1], "rb")) != NULL) {
        int bytes_width;
        printf("Offset  ");
        bytes_width = LINE_SIZE * 3 - 1;
        printf("%*s", (bytes_width) / 2 + 3, "Bytes");
        printf("%*s", (bytes_width) / 2 - 2, " ");
        printf("  %*s\n", LINE_SIZE, "Characters");

        printf("------  ");
        for(int i = 0; i < bytes_width; i++)
            putchar('-');
        printf("  ");
        for(int i = 0; i < LINE_SIZE; i++)
            putchar('-');
        printf("\n");

        while((ch = fgetc(fp)) != EOF) {
            if((offset % LINE_SIZE) == 0) {
                if(offset != 0) {
                    chars[LINE_SIZE] = '\0';
                    putchar(' ');
                    puts(chars);
                }

                printf("%6d  ", offset);
            }
            printf("%02X ", ch);
            chars[(offset % LINE_SIZE)] = isprint(ch) ? ch : '.';
            offset++;
        }
        for(int i = offset % LINE_SIZE ; i != 0 && i < LINE_SIZE; i++)
            printf("%2s ", " ");
        chars[(offset % LINE_SIZE)] = '\0';
        printf(" %s\n", chars); 

        fclose(fp);
    } else {
        fprintf(stderr, "Failed to open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    return 0;
}
