#ifndef STACK_H
#include <stdbool.h>
#define STACK_H

#define STACK_LENGTH 100
extern int stack[];
extern int top;

void push(int num);
int pop(void);
bool is_empty(void);
void stack_overflow(void);
void stack_underflow(void);

#endif
