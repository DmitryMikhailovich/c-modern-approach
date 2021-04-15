#include <stdio.h>

int count_periods(const char *filename) {
    FILE *fp;
    int ch;
    int n = 0;

    if ((fp = fopen(filename, "r")) != NULL) {
        while((ch = fgetc(fp)) != EOF)
            if (ch == '.')
                n++;
        fclose(fp);
    }

    return n;
}
