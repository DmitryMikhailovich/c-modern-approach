#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int main(void) {
    char *c, *native;

    c = setlocale(LC_ALL, "C");
    if(c == NULL) {
        printf("C locale info is not available\n");
        exit(EXIT_FAILURE);
    }

    native = setlocale(LC_ALL, "");

    if(native == NULL) {
        printf("Native locale info is not available\n");
        exit(EXIT_FAILURE);
    }

    if (strcmp(native, c) == 0) {
        printf("Native locale is the same as the C locale\n");
    } else {
        printf("Native locale (%s) is not the same as the C locale\n", native);
    }

    return 0;

}
