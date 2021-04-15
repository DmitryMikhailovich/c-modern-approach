#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "5_stack.h"

int stack[STACK_LENGTH];
int top = 0;


void push(int num) {
    if(top + 1 >= STACK_LENGTH)
        stack_overflow();
    else
        stack[top++] = num;
}

int pop(void) {
    if(is_empty())
        stack_underflow();
    else
        return stack[--top];
}

bool is_empty(void) {
    return top == 0;
}

void stack_overflow(void) {
    printf("Expression is too complex\n");
    exit(EXIT_FAILURE);
}

void stack_underflow(void) {
    printf("Not enough operands in expression\n");
    exit(EXIT_FAILURE);
}
