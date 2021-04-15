#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

#define STACK_LENGTH 100
#define N 500


void push(int num);
int pop(void);
bool is_empty(void);
void stack_overflow(void);
void stack_underflow(void);
int parse_num(char ch);
bool isoperator(char ch);
void operate(char operator);
void read_expr();

int evaluate_RPN_expression(const char *expression);
int stack[STACK_LENGTH];
int top = 0;


int main(void)
{
    for(;;) {
        read_expr();
    }
    return 0;
}

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
    char ch, expression[N+1]; 
    int i = 0;
    printf("Enter an RPN expression: ");
    while((ch = getchar()) != '\n') {
        if(tolower(ch) == 'q')
             exit(EXIT_SUCCESS);

        if(i >= N)
             break;
        expression[i++] = ch;
    }
    expression[i] = '\0';
    printf("Value of expression: %d\n", evaluate_RPN_expression(expression));
}


int evaluate_RPN_expression(const char *expression) {

    const char *p = expression;
    char ch;
    while(*p) { 
        ch = *p;
        if(ch == '\n')
            break;
        if(isdigit(ch))
            push(parse_num(ch));
        else if(isoperator(ch))
            operate(ch);
        else if(ch == '=') {
            return pop();
        }
        p++;
    }
    return 0;

}
