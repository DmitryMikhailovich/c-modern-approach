#include <stdio.h>

#define M(x,y) ((x)^(y),(y)^=(x),(x)^=(y))

int main(void) {
    unsigned int x = 4, y = 16;
    printf("x=%d,y=%d,", x, y);
    M(x,y);
    printf("after M(x,y): x=%d,y=%d\n", x, y);

    return 0;

}
