#include <stdio.h>
#include <stdlib.h>

void *my_malloc(int size);



void *my_malloc(int size) {
    void *p = malloc(size);
    if (p == NULL) {
        printf("Failed to allocate memory\n");
        exit(EXIT_FAILURE);
    }
    return p;
}

