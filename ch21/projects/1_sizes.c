#include <stdio.h>
#include <stddef.h>

int main(void) {
    struct s {
        int a;
        int b;
        int c;
    };
    struct s sinst;

    printf("sizeof(s)=%d\n", sizeof(sinst));
    printf("sizeof(s.a)=%d\n", sizeof(sinst.a));
    printf("sizeof(s.b)=%d\n", sizeof(sinst.b));
    printf("sizeof(s.c)=%d\n", sizeof(sinst.c));

    printf("offsetof(s.a)=%d\n", offsetof(struct s,a));
    printf("offsetof(s.b)=%d\n", offsetof(struct s,b));
    printf("offsetof(s.c)=%d\n", offsetof(struct s,c));

    return 0;
}
