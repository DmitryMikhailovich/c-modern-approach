#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define N 50

bool are_anagrams(const char *word1, const char *word2);

int main(void)
{
    char ch, word1[N+1], word2[N+1];
    int i;

    i = 0;
    printf("Enter first word: ");
    while((ch = getchar()) != '\n') {
        word1[i++] = ch;
        if(i >= N) {
          break;
        }
    }
    word1[i] = '\0';

    i = 0;
    printf("Enter second word: ");
    while((ch = getchar()) != '\n') {
        word2[i++] = ch;
        if(i >= N) {
          break;
        }
    }
    word2[i] = '\0';
    printf("Words are '%s' and '%s'\n", word1, word2);
    if(are_anagrams(word1, word2))
        printf("The words are anagrams\n");
    else
        printf("The words are not anagrams\n");
    return 0;
} 

bool are_anagrams(const char *word1, const char *word2) {
   
    int counter[26] = {0};
    const char *p;

    p = word1;
    while(*p) {
        if(isalpha(*p))
            counter[tolower(*p) - 'a'] += 1;
       p++;
   }
 
    p = word2;
    while(*p) {
        if(isalpha(*p))
            counter[tolower(*p) - 'a'] -= 1;
       p++;
   }

   for(int i = 0; i < 26; i++) 
       if(counter[i] != 0)
           return false;
   return true;
}
