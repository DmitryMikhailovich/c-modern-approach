#include <stdio.h>

unsigned int rotate_left(unsigned int i, int n);
unsigned int rotate_right(unsigned int i, int n);

int main(void) {
    unsigned int i = 0x12345678;
    printf("rotate_left(%x, 4)=%x\n", i, rotate_left(i, 4));
    printf("rotate_right(%x, 4)=%x\n", i, rotate_right(i, 4));
    return 0;
}

unsigned int rotate_left(unsigned int i, int n) {
    int num_bits = 8 * sizeof(i);
    return (i << n) + (i >> num_bits - n);
}

unsigned int rotate_right(unsigned int i, int n) {
    int num_bits = 8 * sizeof(i);
    return (i >> n) + (i << num_bits - n);
}

