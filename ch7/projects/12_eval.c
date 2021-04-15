#include <stdio.h>

int main(void)
{
    float operand, result;
    char operator;
    printf("Enter an expression: ");
    scanf("%f", &result); 
    for(;;) {
        while((operator = getchar()) == ' ')
            ;
        if(operator == '\n')
            break;
        scanf("%f", &operand);
        switch(operator) {
            case '+':
                result += operand;
                break;
            case '-':
                result -= operand;
                break;
            case '/':
                result /= operand;
                break;
            case '*':
                result *= operand;
                break;
        }
    }
    printf("Value of expression: %.2f\n", result);
    return 0;
}
