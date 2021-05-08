#include <stdlib.h>
#include <stdio.h>

void print_prefix(void);
void print_suffix(void);

int main(void) {
    atexit(print_suffix);
    atexit(print_prefix);

    return 0;
}

void print_prefix(void) {
    printf("That's all, ");
}

void print_suffix(void) {
    printf("folks!\n");
}
