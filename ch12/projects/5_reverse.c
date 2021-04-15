#include <stdio.h>

#define N 50

int main(void) {
    char sentence[N], *p;
    char ch, terminal = ' ';
    int word_length, n = N;
    printf("Enter a sentence: ");
    for(p = &sentence[0]; p < &sentence[0] + n; p++) {
        *p = getchar();
        if(*p == '\n')
            break;
    }
    p--;
    
    if(*p == '?' || *p == '!' || *p == '.') {
        terminal = *p;
        p--;
        n--;
    }
    
    word_length = 0;
    for(; p >= &sentence[0]; p--) {
        if(*p != ' ') {
            word_length++;
            continue;
        } else {
            for(char *q = p+1; q < p + 1 + word_length; q++) 
                printf("%c", *q);
            printf(" ");
            word_length = 0;
        }
    }
    for(char *q = &sentence[0]; q < &sentence[0] + word_length; q++) 
        printf("%c", *q);
    printf("%c\n", terminal);
    return 0;
}
