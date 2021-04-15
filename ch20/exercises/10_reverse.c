#include <stdio.h>

unsigned int reverse_bits(unsigned int n);

int main(void) {

    unsigned int n = 14;
    printf("%x reversed: %x\n", n, reverse_bits(n));

    return 0;
}

unsigned int reverse_bits(unsigned int n) {
    int num_bits = sizeof(n) * 8;
    int i;
    unsigned int res = 0;
    for(i = 0; i < num_bits; i++) {
        res |= ((n >> num_bits - 1 - i) & 1) << i;
    }
    return res;
}
