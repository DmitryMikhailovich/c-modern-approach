#include <stdio.h>
#include <stdarg.h>
#include <math.h>

int d_printf(const char * restrict format, ...);

int main(void) {

    d_printf("Number %d, number %d, string %s\n", 123, 456, 789);

    return 0;
}

int d_printf(const char * restrict format, ...) {

    va_list ap;
    char ch;
    const char *ptr = format;
    int i = 0, arg, power, t;

    va_start(ap, format);

    for (ch = *ptr ; ch != '\0' ; ch = *(++ptr)) {
        if (ch != '%') {
            putchar(ch);
            continue;
        }
        ch = *(++ptr);

        if (ch != 'd')
            continue;

        arg = va_arg(ap, int);
        for (power = 0, t = arg; t > 9; t = t / 10)
            power++;

        for (t = arg; power > 0; power--) {
            putchar('0' + (int) (t / pow(10, power))); 
            t = t % (int) pow(10, power);
        }
        putchar('0' + t);

        i++;
    }

    va_end(ap);
    return i;

}
