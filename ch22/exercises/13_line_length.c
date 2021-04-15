#include <stdio.h>
#include <stdlib.h>

int line_length(const char *filename, int n);

int main(int argc, char *argv[]) {
    if(argc < 3) {
        fprintf(stderr, "Usage: line_length FILE N\n");
        exit(EXIT_FAILURE);
    }
    char *filename = argv[1];
    int n = atoi(argv[2]);
    printf("Length of line %d in %s is %d\n", n, filename, line_length(filename, n));

    return 0;

}


int line_length(const char *filename, int n) {
    FILE *fp;
    int ch; 
    int i = 1, len = 0;
    if((fp = fopen(filename, "r")) != NULL) {
        while(i < n && (ch = fgetc(fp)) != EOF) 
            if(ch == '\n')
                i++;
        while((ch = fgetc(fp)) != EOF && ch != '\n')
            len++;
    }
    return len;
}

