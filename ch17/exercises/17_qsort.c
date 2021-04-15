#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b);

int main(void) {
    int a[100] = {0, 2, 3, 4, 5, 0, 1, 1};
    qsort(&a[50], 50, sizeof(a[0]), compare);
    
    return 0;
}

int compare(const void *a, const void *b) {
    
    if(*((int*) a) < *((int*) b))
        return -1;
    else if(*((int*) a) > *((int*) b))
        return 1;
    return 0;
}
