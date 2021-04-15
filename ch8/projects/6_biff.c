#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char ch; 
    
    printf("Enter message: ");
    while((ch = getchar()) != '\n') {
        ch = toupper(ch);
        switch(ch) {
            case 'A': ch = '4'; break;
            case 'B': ch = '8'; break;
            case 'E': ch = 'E'; break;
            case 'I': ch = '1'; break;
            case 'O': ch = '0'; break;
            case 'S': ch = '5'; break;
        }
        printf("%c", ch);
    }
    printf("!!!!!!!!!!\n");
    return 0;
}
