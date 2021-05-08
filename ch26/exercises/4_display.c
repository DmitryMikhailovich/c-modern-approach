#include <stdarg.h>
#include <stdio.h>


int display(int n, ...);

int main(void) {
    display(4, "Special", "Agent", "Dale", "Cooper");

    return 0;
}

int display(int n, ...) {
    char *str;
    va_list ap;

    va_start(ap, n);

    for(int i = 0; i < n; i++) {
        str = va_arg(ap, char *);
        printf("%s ", str);
    }
    putchar('\n');
    return n;
} 
