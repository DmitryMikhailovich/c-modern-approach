#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "stack.h"


struct node *top = NULL;

bool push(int num) {
    struct node *new = malloc(sizeof(struct node));
    if (new == NULL)
        return false;
    new->value = num;
    new->prev = top;
    top = new;
    return true;
}

int pop(void) {
    if(is_empty()) {
        stack_underflow();
    }
    struct node *item = top;
    int i;
    top = item->prev;
    i = item->value;
    free(item);
    return i;
}

bool is_empty(void) {
    return top == NULL;
}

void stack_overflow(void) {
    printf("Expression is too complex\n");
    exit(EXIT_FAILURE);
}

void stack_underflow(void) {
    printf("Not enough operands in expression\n");
    exit(EXIT_FAILURE);
}
