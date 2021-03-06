#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>

#define STACK_SIZE 100

char contents[STACK_SIZE];
int top = 0;
int underflowed = 0;

void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(char c);
char pop(void);
void stack_overflow(void);
void stack_underflow(void);



int main(void)
{
    char ch, popped;
    int not_properly = 0;
    printf("Enter parentheses and/or braces: ");
    while((ch = getchar()) != '\n') {
        if(!(ch == '(' || ch == ')' || ch == '{' || ch == '}'))
            continue;
        if(ch == '(' || ch == '{')
            push(ch);
        else {
            popped = pop();
            if(ch == ')' && popped != '(' || ch =='{' && popped != '}')
                not_properly++;
        } 
    }
    if(not_properly > 0 || underflowed > 0 || !is_empty())
        printf("Parentheses/braces are not nested properly\n");
    else
        printf("Parenthesese/braces are nested properly\n");
    return 0;
}

void make_empty(void)
{
    top = 0;
}

bool is_empty(void)
{
    return top == 0;
}

bool is_full(void)
{
    return top == STACK_SIZE;
}

void push(char c)
{
    if(is_full())
        stack_overflow();
    else
        contents[top++] = c;
}

char pop(void)
{
    if(is_empty())
        stack_underflow();
    else
        return contents[--top];
}

void stack_overflow(void)
{
    printf("Stack overflow\n");
    exit(EXIT_FAILURE);
}

void stack_underflow(void)
{
    printf("Stack underflow\n");
    underflowed++;
}
