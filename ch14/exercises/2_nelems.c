#include <stdio.h>

#define NELEMS(a) sizeof(a)/sizeof(a[0])

int main(void) {

    int a[5] = {1};
    printf("Number of elements in a is %d\n", NELEMS(a));
    return 0;
}
