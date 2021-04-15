#include <stdio.h>

int main(void) {

    union {
        float f;
        struct {
            unsigned int fraction: 23;
            unsigned int exponent: 8;
            unsigned int sign: 1;
        } s;
    } u;

    u.s.sign = 1;
    u.s.exponent = 128;
    u.s.fraction = 0;

    printf("%f\n", u.f);
    
    return 0;
}
