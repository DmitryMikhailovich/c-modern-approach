#include <stdio.h>

#define GENERIC_MAX(type)      \
type type##_max(type x, type y) \
{ \
    return x > y ? x : y;   \
}

typedef  unsigned long ulong;

GENERIC_MAX(ulong)

int main(void) {
    printf("Generic max of unsigned longs: %lx\n", ulong_max(1UL, 2UL));


    return 0;
}
