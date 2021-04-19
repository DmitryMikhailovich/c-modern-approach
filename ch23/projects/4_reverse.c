#include <stdio.h>
#include <string.h>

#define LEN 100
#define MAX_WORDS 50

int main(void) {
    int ch;   
    char str[LEN+1], *words[MAX_WORDS], *word;
    int n = 0, word_count = 0;
    
    printf("Enter space-separated series of words: ");
    while((ch = getchar()) != '\n' && n < LEN) {
      str[n++] = ch;
    }
    str[n] = '\0';

    words[word_count++] = strtok(str, " ");
    while((word = strtok(NULL, " ")) != NULL && word_count < MAX_WORDS)
       words[word_count++] = word;

    for(int i = word_count-1; i >= 0; i--) {
        if(i != word_count-1)
            putchar(' ');
        printf("%s", words[i]);
    }
    putchar('\n');
        
    return 0;
} 
   
