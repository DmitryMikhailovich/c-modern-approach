#include <stdio.h>

#define M 10


int main(void) {
    #if M
        printf("A\n");
    #endif

    #ifdef M
        printf("B\n");
    #endif

    #ifndef M
        printf("C\n");
    #endif
        
    #if defined(M)
        printf("D\n");
    #endif

    #if !defined(M)
        printf("E\n");
    #endif

    return 0;
}
