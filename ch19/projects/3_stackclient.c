#include <stdio.h>
#include "3_stackADT.h"

int main(void) {
    Stack s1, s2;
    int n;

    s1 = create();
    s2 = create();

    push(s1, 1);
    push(s1, 2);

    n = pop(s1);
    printf("Popped %d from s1, length of s1: %d\n", n, length(s1));
    push(s2, n);
    n = pop(s1);
    printf("Popped %d from s1, length of s1: %d\n", n, length(s1));
    push(s2, n);

    destroy(s1);

    while(!is_empty(s2))
        printf("Popped %d from s2, length of s2: %d\n", pop(s2), length(s2));

    push(s2, 3);
    make_empty(s2);
    if(is_empty(s2))
        printf("s2 is empty\n");
    else
        printf("s2 is not empty\n");

    destroy(s2);

    return 0;
}
    
    
