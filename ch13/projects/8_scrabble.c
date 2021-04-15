#include <stdio.h>
#include <ctype.h>

#define N 50

int compute_scrabble_value(const char *word);
int read_line(char str[], int n);

int main(void)
{
    int value;
    char ch;
    char word[N+1];
    printf("Enter a word: ");
    read_line(word, N);
    value = compute_scrabble_value(word);
    printf("Scrabble value: %d\n", value);
    return 0;
} 

int compute_scrabble_value(const char *word) {

    int value = 0;
    char ch;
    while((ch = *word++))
    {
        ch = toupper(ch);
        switch(ch) {
            case 'A': case 'E': case 'I': case 'L': case 'N': case 'O':
            case 'R': case 'S': case 'T': case 'U': value += 1; break;
            
            case 'D': case 'G': value += 2; break;
            
            case 'B': case 'C': case 'M': case 'P': value += 3; break;

            case 'F': case 'H': case 'V': case 'W': case 'Y': value += 4; break;
            
            case 'K': value += 5; break;
            
            case 'J': case 'X': value += 8; break;
        
            case 'Q': case 'Z': value += 10; break;
        } 
    }

    return value;
}

int read_line(char str[], int n)
{
  int ch, i = 0;
  while((ch = getchar()) != '\n')
    if(i < n)
      str[i++] = ch;
  str[i] = '\0';
  return i;
}
