#include <stdio.h>

int main(void) {
    FILE *fp;
    int n = 5;

    if((fp = fopen("15_fseek.c", "rb")) != NULL) {
        fseek(fp, n * 64L, SEEK_SET); 
        fseek(fp, -64L, SEEK_END);
        fseek(fp, 64L, SEEK_CUR);
        fseek(fp, -2 * 64L, SEEK_CUR);

    }

    return 0;

}
