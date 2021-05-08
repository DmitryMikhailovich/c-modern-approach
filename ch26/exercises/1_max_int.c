#include <stdarg.h>
#include <stdio.h>

int max_int(int n1, ...);

int main(void) {
    
    printf("Largest of %d, %d, %d is %d\n", 53, 29, 98, max_int(53, 29, 98, 0));

    return 0;
}


int max_int(int n1, ...) {
    va_list ap;
    int current, largest;

    va_start(ap, n1);
    largest = n1;

    for (;;) {
        current = va_arg(ap, int);
        if (current == 0)
            break;
        if (current > largest)
            largest = current;
    }

    va_end(ap);
    return largest;
}
