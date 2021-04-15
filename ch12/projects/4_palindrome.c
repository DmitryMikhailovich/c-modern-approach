#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define N 100

bool is_palindrome(char msg[N], int n);

int main(void)
{
    char msg[N], c, *p;

    
    printf("Enter a message: ");
    for(p = msg; p < msg + N; p++) {
        *p = getchar();
        if(*p == '\n')
            break;
    }
    if(is_palindrome(msg, p - msg))
        printf("Palindrome\n");
    else
        printf("Not a palindrome\n");

    return 0;
}
   

 
bool is_palindrome(char msg[N], int n)
{
    char *q = msg, *p = msg + n;
    while(q < p) {
        if(!isalpha(*p)) {
            p--;
            continue;
        }
        if(!isalpha(*q)) {
            q++; 
            continue;
        }
        if(tolower(*(q++)) != tolower(*(p--))) {
            return false;
        }
    }
    return true;
} 
