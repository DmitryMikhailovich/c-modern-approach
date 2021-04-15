#include <stdio.h>
#include <stdlib.h>

int *create_array(int n, int initial_value);


int main(void) {
    int *a = create_array(4, 5);

    printf("%d\n", a[0]);
    return 0;
}

int *create_array(int n, int initial_value) {
    int *p = malloc(sizeof(int) * n);
    if (p == NULL) {
        return p;
    }
    p[0] = initial_value;    
    return p;
}

