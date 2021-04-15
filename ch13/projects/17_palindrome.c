#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define N 100

bool is_palindrome(const char *message);

int main(void)
{
    char msg[N], c, *p;

    
    printf("Enter a message: ");
    for(p = msg; p < msg + N; p++) {
        *p = getchar();
        if(*p == '\n')
            break;
    }
    if(is_palindrome(msg))
        printf("Palindrome\n");
    else
        printf("Not a palindrome\n");

    return 0;
}
   

 
bool is_palindrome(const char *message)
{
    const char *q = message, *p = message;
    while(*p)
        p++;
    p--;
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
