#include <stdlib.h>
#include <stdio.h>
#include "4_stackADT.h"

int main(void) {
    Stack s1, s2;
    int *n;
    int *i;

    s1 = create();
    s2 = create();

    i = malloc(sizeof(int));
    *i = 1;
    push(s1, i);
    i = malloc(sizeof(int));
    *i = 2;
    push(s1, i);

    n = pop(s1);
    printf("Popped %d from s1\n", *n);
    push(s2, n);
    n = pop(s1);
    printf("Popped %d from s1\n", *n);
    push(s2, n);

    destroy(s1);

    while(!is_empty(s2))
        printf("Popped %d from s2\n", *((int *) pop(s2)));

    i = malloc(sizeof(int));
    *i = 3;
    push(s2, i);
    make_empty(s2);
    if(is_empty(s2))
        printf("s2 is empty\n");
    else
        printf("s2 is not empty\n");

    destroy(s2);

    return 0;
}
    
    
