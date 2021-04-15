#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *fp;
    int failures = 0;

    if(argc < 2) {
        printf("usage: canopen filename, [filename, [...]]\n");
        exit(EXIT_FAILURE);
    }
    for(int i = 1; i < argc; i++) {

        if((fp = fopen(argv[i], "r")) == NULL) {
            printf("%s can't be opened\n", argv[i]);
            failures++;
        }

        printf("%s can be opened\n", argv[i]);
        fclose(fp);
    }
    if(failures > 0)
        exit(EXIT_FAILURE);
    return 0;
}
