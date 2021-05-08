#include <stdio.h>
#include <stdarg.h>
#include <math.h>

int ds_printf(const char * restrict format, ...);

int main(void) {

    ds_printf("Number %d, number %d, string %s\n", 123, 456, "str");

    return 0;
}

int ds_printf(const char * restrict format, ...) {

    va_list ap;
    char ch, *arg_str;
    const char *ptr = format;
    int i = 0, arg_int, power, t;

    va_start(ap, format);

    for (ch = *ptr ; ch != '\0' ; ch = *(++ptr)) {
        if (ch != '%') {
            putchar(ch);
            continue;
        }
        ch = *(++ptr);

        if (ch == 'd') {

            arg_int = va_arg(ap, int);
            for (power = 0, t = arg_int; t > 9; t = t / 10)
                power++;

            for (t = arg_int; power > 0; power--) {
                putchar('0' + (int) (t / pow(10, power))); 
                t = t % (int) pow(10, power);
            }
            putchar('0' + t);

        } else if (ch == 's') {
            arg_str = va_arg(ap, char *);
            for (char c = *arg_str ; c != '\0' ; c = *++arg_str)
                putchar(c);
        } else {
            continue;
        }

        i++;
    }

    va_end(ap);
    return i;

}
