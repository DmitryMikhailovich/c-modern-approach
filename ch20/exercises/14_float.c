#include <stdio.h>

union IEEE_float {
    float f;
    struct {
        unsigned int fraction: 23, exponent: 8, sign: 1; 
    } sf;
};

int main(void) {

    union IEEE_float value;
    value.f = 123.456;
    printf("Value: %f\n", value.f);
    printf("Sign: %x\n", value.sf.sign);
    printf("Exponent: %x\n", value.sf.exponent);
    printf("Fraction: %x\n", value.sf.fraction);
    return 0;
}
