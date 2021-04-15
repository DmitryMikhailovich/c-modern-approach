#include <stdio.h>

#define WORDS 30
#define N 20

int main(void) {
    char sentence[WORDS][N+1];
    char ch, prev_ch = ' ', terminal = ' ';
    int n = 0, i = 0, word_length;
    printf("Enter a sentence: ");
    while((ch = getchar()) != '\n') {
        if(n >= WORDS-1) {
           sentence[n][i] = '\0';
           break;
        }

        if(ch == ' ' && ch == prev_ch) {
           continue;
        } 

        if((ch == ' ' && ch != prev_ch) || i >= N) {
           sentence[n][i] = '\0';
           i = 0;
           n++;
           prev_ch = ch;
           continue;
        }
        sentence[n][i++] = ch;
        prev_ch = ch; 
    }
 
    if(sentence[n][i-1] == '!' || sentence[n][i-1] == '?' || sentence[n][i-1] == '.') {
         terminal = sentence[n][i-1];
         sentence[n][i-1] = '\0';
    } else {
         sentence[n][i] = '\0';
    }

    
    for(i = n; i > 0; i--) {
        printf("%s ", sentence[i]);
    }
   
    printf("%s%c\n", sentence[0], terminal);
    return 0;
}
