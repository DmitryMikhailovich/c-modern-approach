#include <stdio.h>
#include <ctype.h>

#define N 50

int compute_vowel_count(const char *sentence);
int read_line(char str[], int n);

int main(void)
{
    char sentence[N+1];
    int count;
    printf("Enter a sentence: ");
    read_line(sentence, N);
    count = compute_vowel_count(sentence);
    printf("Your sentence contains %d vowels\n", count);
    return 0;
}


int compute_vowel_count(const char *sentence) {
    char ch;
    int count = 0;
    while((ch = *sentence++)) {
        ch = toupper(ch);
        switch(ch) {
            case 'A': case 'E': case 'I': case 'O': case 'U':
            count++;
            break;
        }
    }

    return count;
}

int read_line(char str[], int n) {

 int ch, i = 0;
 while((ch = getchar()) != '\n')
   if(i < n)
    str[i++] = ch;
  str[i] = '\0';
  return i;
}
