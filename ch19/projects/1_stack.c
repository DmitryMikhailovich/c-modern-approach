#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include "stackADT.h"

int main(void)
{
    char ch, popped;
    int not_properly = 0;
    int underflowed = 0;

    Stack s = create();
    printf("Enter parentheses and/or braces: ");
    while((ch = getchar()) != '\n') {
        if(!(ch == '(' || ch == ')' || ch == '{' || ch == '}'))
            continue;
        if(ch == '(' || ch == '{')
            push(s, ch);
        else {
            popped = pop(s);
            if(ch == ')' && popped != '(' || ch =='{' && popped != '}')
                not_properly++;
        } 
    }
    if(not_properly > 0 || underflowed > 0 || !is_empty(s))
        printf("Parentheses/braces are not nested properly\n");
    else
        printf("Parenthesese/braces are nested properly\n");
    return 0;
}
