#include <stdio.h>

#define N 100

void reverse(char *message);

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
    *p = '\0';
    reverse(msg);
    printf("Reversal is: %s\n", msg);
    
    return 0;
}

void reverse(char *message) {
    char *p, *q, ch;
    p = message;
    q = message;
    while(*q)
       q++;

    q--;
    while(q >= p) {
        ch = *q;
        *q = *p;
        *p = ch;
        q--;
        p++;
    }
}
