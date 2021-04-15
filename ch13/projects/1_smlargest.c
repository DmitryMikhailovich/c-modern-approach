#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define N 100

int main(void) {
  char smallest_word[N], largest_word[N], word[N]; 
  printf("Enter word: ");
  scanf("%s", word);
  strcpy(smallest_word, strcpy(largest_word, word));

  while(true) {
    printf("Enter word: ");
    scanf("%s", word);
    if(strcmp(word, smallest_word) < 0)
       strcpy(smallest_word, word);
    if(strcmp(word, largest_word) > 0)
       strcpy(largest_word, word);
    if(strlen(word) == 4) {
       break;
    }
  }
  printf("Smallest word: %s\n", smallest_word);
  printf("Largest word: %s\n", largest_word);
  return 0;
  
}
