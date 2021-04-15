#include <stdio.h>
#include <stdlib.h>

int sum(int (*f)(int), int start, int end);
int sqr(int i);

int main(void) {
    int s = sum(sqr, 0, 3);
    printf("sum(sqr, 0, 3)=%d\n", s);
    return 0;
}    

int sum(int (*f)(int), int start, int end) {

    int s = 0;
    for (int i = start; i <= end; i++)
        s += f(i);
    return s;
}

int sqr(int i) {
    return i * i;
}
