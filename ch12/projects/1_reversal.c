#include <stdio.h>

#define N 100

int main(void)
{
    char msg[N];
    char c, *p;

    printf("Enter a message: ");
    for(p = msg; p < msg + N; p++) {
        *p = getchar();
        if(*p == '\n')
            break;
    }
    printf("Reversal is: ");
    while(p >= msg)
        putchar(*p--);
    printf("\n");
    

    return 0;
}
