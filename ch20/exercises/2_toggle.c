#include <stdio.h>

unsigned int toggle(unsigned int i, int bit);

int main(void) {
    unsigned int i;

    i = 18;

    printf("Result of toggling bit 4 of %d is %d\n", i, toggle(i, 4));
    
    i = 0;
    printf("Result of toggling bit 4 of %d is %d\n", i, toggle(i, 4));

    return 0;
}
     

unsigned int toggle(unsigned int i, int bit) {
    return i ^ 1 << bit;
}
