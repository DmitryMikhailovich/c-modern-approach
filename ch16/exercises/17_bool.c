#include <stdio.h>


int main(void) {
    enum {FALSE, TRUE} b;
    int i = 0;
    
    b = FALSE;
    b = i; // not safe
    b++; // not safe
    i = b;
    i = 2 * b + 1;
    return 0;
}
