#include <stdio.h>

#define GET_RED(c) ((c) >> 16) & 0x00FF
#define GET_GREEN(c) ((c) >> 8) & 0x00FF
#define GET_BLUE(c) (c) & 0x00FF


int main(void) {

    long int c = 8421824;
    printf("Red: %d\n", GET_RED(c));
    printf("Green: %d\n", GET_GREEN(c)); 

    printf("Blue: %d\n", GET_BLUE(c));

    return 0;
}

