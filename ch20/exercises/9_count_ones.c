#include <stdio.h>

int count_ones(unsigned char ch);

int main(void) {
    int ch = 'a';

    printf("Ones in %c: %d\n", ch, count_ones(ch));

    return 0;
}

int count_ones(unsigned char ch) {
    return (ch >> 0 & 1)
         + (ch >> 1 & 1)
         + (ch >> 2 & 1)
         + (ch >> 3 & 1)
         + (ch >> 4 & 1)
         + (ch >> 5 & 1)
         + (ch >> 6 & 1)
         + (ch >> 7 & 1);
}
