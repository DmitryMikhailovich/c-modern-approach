#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include "5_stack.h"

int parse_num(char ch);
bool isoperator(char ch);
void operate(char operator);
void read_expr();


int main(void)
{
    for(;;) {
        read_expr();
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

void operate(char operator) {
    int left_operand, right_operand, result;
    right_operand = pop();
    left_operand = pop();
    switch(operator) {
        case '*': result = left_operand * right_operand; break;
        case '-': result = left_operand - right_operand; break;
        case '/': result = left_operand / right_operand; break;
        case '+': result = left_operand + right_operand; break;
        default:
            printf("Unknown operator %c\n", operator);
            exit(EXIT_FAILURE);
    }
    push(result); 
}

void read_expr(void)
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
            push(parse_num(ch));
        else if(isoperator(ch))
            operate(ch);
        else if(ch == '=') {
            printf("Value of expression: %d\n", pop());
            break;
        }
    }
}
