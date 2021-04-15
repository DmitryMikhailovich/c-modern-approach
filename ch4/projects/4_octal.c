#include <stdio.h>

int main(void)
{
    int num, result;
    printf("Enter a number between 0 and 32767: ");
    scanf("%5d", &num);
    result = num % 8;
    result += 10 * ((num / 8) % 8);
    result += 100 * ((num / 64) % 8);
    result += 1000 * ((num / 512) % 8);
    result += 10000 * ((num / 4096) % 8); 
    printf("In octal, your number is: %05d\n", result);
    
    return 0;
}
