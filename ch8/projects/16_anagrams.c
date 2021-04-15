#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char ch;
    int counter[26] = {0};

    printf("Enter first word: ");
    while((ch = getchar()) != '\n')
        if(isalpha(ch))
            counter[tolower(ch) - 'a'] += 1;
    printf("Enter second word: ");
    while((ch = getchar()) != '\n')
        if(isalpha(ch))
            counter[tolower(ch) - 'a'] -= 1;

   for(int i = 0; i < 26; i++) {
        if(counter[i] != 0) {
            printf("The words are not anagrams\n");
            return 0; 
        }
  }
    printf("The words are anagrams\n");
    return 0;
} 
