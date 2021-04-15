#include <stdio.h>

#define MK_COLOR(r,g,b) ((long) ((long)(r) << 16) + ((long)(g) << 8) + (b))

int main(void) {
    printf("MK_COLOR(%d,%d,%d)=%d\n", 128, 103, 43, MK_COLOR(128,103,43));

    return 0;
}
