#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include "stackADT.h"


int parse_num(char ch);
bool isoperator(char ch);
void operate(Stack s, char operator);
void read_expr(Stack s);

int main(void)
{
    Stack s = create();
    for(;;) {
        read_expr(s);
    }
    return 0;
}


int parse_num(char ch) {
    switch(ch) {
        case '0': return 0;
        case '1': return 1;
        case '2': return 2;
        case '3': return 3;
        case '4': return 4;
        case '5': return 5;
        case '6': return 6;
        case '7': return 7;
        case '8': return 8;
        case '9': return 9;
        default: 
            printf("%c is not a decimal digit\n", ch);
            exit(EXIT_FAILURE);
    }
}

bool isoperator(char ch) {
    return ch == '*' || ch == '+' || ch == '-' || ch == '/';
}

void operate(Stack s, char operator) {
    int left_operand, right_operand, result;
    right_operand = pop(s);
    left_operand = pop(s);
    switch(operator) {
        case '*': result = left_operand * right_operand; break;
        case '-': result = left_operand - right_operand; break;
        case '/': result = left_operand / right_operand; break;
        case '+': result = left_operand + right_operand; break;
        default:
            printf("Unknown operator %c\n", operator);
            exit(EXIT_FAILURE);
    }
    push(s, result); 
}

void read_expr(Stack s)
{
    char ch; 
    printf("Enter an RPN expression: ");
    for(;;) { 
        scanf(" %c", &ch);
        if(ch == '\n')
            break;
        if(tolower(ch) == 'q')
            exit(EXIT_SUCCESS);
        if(isdigit(ch))
            push(s, parse_num(ch));
        else if(isoperator(ch))
            operate(s, ch);
        else if(ch == '=') {
            printf("Value of expression: %d\n", pop(s));
            break;
        }
    }
}
