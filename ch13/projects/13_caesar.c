#include <stdio.h>

void encrypt(char *message, int shift);

int main(void)
{
    int shift, len = 0;
    char msg[80], ch;

    printf("Enter message to be encrypted: ");
    while((ch = getchar()) != '\n')
        msg[len++] = ch;
    printf("Enter shift amount (1-25): ");
    scanf("%d", &shift);
    if(shift < 1 || shift > 25) {
        printf("Shift should be between 1 and 25\n");
        return 1;
    }
    encrypt(msg, shift);
    printf("Encrypted message: %s\n", msg);
   
    return 0;
}


void encrypt(char *message, int shift) {
    char *p = message;
    char ch;
    while(*p) {
        ch = *p;
        if(ch >= 'a' && ch <= 'z')
            ch = ((ch - 'a') + shift) % 26 + 'a';
        else if(ch >= 'A' && ch <= 'Z')
            ch = ((ch - 'A') + shift) % 26 + 'A';
        *p = ch; 
        p++;
    }


}
