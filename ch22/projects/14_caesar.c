#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    FILE *fdi, *fdo;
    int shift, len = 0;
    char filename[80], encfilename[80+4];
    char ch;

    printf("Enter name of file to be encrypted: ");
    while((ch = getchar()) != '\n')
        filename[len++] = ch;
    strcpy(encfilename, filename);
    strcat(encfilename, ".enc");
    if((fdi = fopen(filename, "rb")) != NULL
        && (fdo = fopen(encfilename, "wb")) != NULL) { 
        printf("Enter shift amount (1-25): ");
        scanf("%d", &shift);
        if(shift < 1 || shift > 25) {
            fprintf(stderr, "Shift should be between 1 and 25\n");
            exit(EXIT_FAILURE);
        }
        while((ch = fgetc(fdi)) != EOF) {
            if(ch >= 'a' && ch <= 'z')
                ch = ((ch - 'a') + shift) % 26 + 'a';
            else if(ch >= 'A' && ch <= 'Z')
                ch = ((ch - 'A') + shift) % 26 + 'A';
            fputc(ch, fdo);
        }
        fclose(fdi);
        fclose(fdo);
    } else {
        fprintf(stderr, "Failed to open one of the files\n");
        exit(EXIT_FAILURE);
    }
    return 0;
}
