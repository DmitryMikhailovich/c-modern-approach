#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *duplicate(const char *str);

int main(void) {
    char *str = "String";
    char *p = duplicate(str);
    printf("%s\n", p);

    return 0;
}

char *duplicate(const char *str) {
    char *p = malloc(strlen(str));
    if (p == NULL) {
        printf("Failed to allocate memory for new string\n");
        exit(EXIT_FAILURE);
    }
    strcpy(p, str);
    return p;
}
