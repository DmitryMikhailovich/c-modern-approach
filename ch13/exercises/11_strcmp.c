#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

int strcmp_p(char *s, char *t);

int strcmp_p(char *s, char *t)
{
    while(*s == *t) {
        if(!*s)
            return 0;
        s++; t++;
    }
    return *s - *t;
}

