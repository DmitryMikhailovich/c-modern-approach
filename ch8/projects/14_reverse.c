#include <stdio.h>

int main(void) {
    char sentence[50];
    char ch, terminal = ' ';
    int n = 0, word_length, i, j;
    printf("Enter a sentence: ");
    while((ch = getchar()) != '\n') {
        sentence[n++] = ch;
    }
    
    if(sentence[n-1] == '?' || sentence[n-1] == '!' || sentence[n-1] == '.') {
        terminal = sentence[n-1];
        n--;
    }
    
    word_length = 0;
    for(int i = n - 1; i >= 0; i--) {
        if(sentence[i] != ' ') {
            word_length++;
            continue;
        } else {
            for(int j = i+1; j < i + 1 + word_length; j++)
                printf("%c", sentence[j]);
            printf(" ");
            word_length = 0;
        }
    }
    for(int j = 0; j < word_length; j++)
        printf("%c", sentence[j]);
    printf("%c\n", terminal);
    return 0;
}
