#include <stdio.h>

int main(void) {
    struct {
        unsigned int flag: 1;
    } s;

    s.flag = 1;
    printf("%d\n", s.flag);

    return 0;
}
