#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define N 100
#define WORD_LEN 20

int read_line(char str[], int n);
void sort(char *words[], int n);
int compare(const void *a, const void *b);

int main(void) {
    char *words[N];
    char word[WORD_LEN+1];
    char *new_word;
    int n = 0;
    int chars_read;
    

    for(;;) {
        printf("Enter word: ");
        chars_read = read_line(word, WORD_LEN);
        if(chars_read == 0)
            break;
        new_word = malloc(sizeof(word));
        if(new_word == NULL) {
            printf("Failed to allocate memory for word\n");
            exit(EXIT_FAILURE);
        }
        strcpy(new_word, word);
        words[n++] = new_word;
    }
    sort(words, n);

    for (int i = 0; i < n; i++)
        printf("%s\n", words[i]);

    return 0;
}


int read_line(char str[], int n) {

    char ch;
    int i = 0;
    while((ch = getchar()) != '\n') {
        if(i < n)
            str[i++] = ch;
    }
    str[i] = '\0';
    return i;
}

void sort(char *words[], int n) {
    qsort(words, n, sizeof(words[0]), compare);
}

int compare(const void *a, const void *b) {
    
    return strcmp(a, b);
}
