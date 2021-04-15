#include <stdio.h>

#define ERROR(fmt,...) fprintf(stderr, fmt, __VA_ARGS__)

int main(void) {

    ERROR("Range error: index = %d, column = %d\n", 1, 2);
    return 0;
}
