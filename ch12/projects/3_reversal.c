#include <stdio.h>
#define N 100

int main(void)
{
    char msg[N], *p, *q = msg;
    char c;

    printf("Enter a message: ");
    for(p = msg; p < msg + N; p++) {
        *p = c;
        if(*p == '\n')
            break;
    }
    printf("Reversal is: ");
    while(p >= q)
        putchar(*p--);
    printf("\n");
    

    return 0;
}
