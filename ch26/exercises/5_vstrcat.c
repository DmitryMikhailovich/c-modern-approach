#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *vstrcat(const char *first, ...);

int main(void) {

    printf("%s\n", vstrcat("Special", "Agent", "Dale", "Cooper", NULL));

    return 0;
}

char *vstrcat(const char *first, ...) {
    char *str;
    char *out_str;
    int mem_req = strlen(first);
    va_list ap;
    va_start(ap, first);
    
    while((str = va_arg(ap, char *)) != NULL)
        mem_req += strlen(str);
    va_end(ap);

    if((out_str = malloc((mem_req + 1) * sizeof(char))) == NULL)
        return NULL;

    strcpy(out_str, first);

    va_start(ap, first);
    
    while((str = va_arg(ap, char *)) != NULL)
        strcat(out_str, str);

    va_end(ap);

    return out_str;
}
