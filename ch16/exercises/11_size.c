#include <stdio.h>

int main(void) {
struct {
    double a;
    union {
        char b[4];
        double c;
        int d;
    } e;
    char f[4];
} s;

printf("size of s: %d\n", sizeof(s));
return 0;
}
