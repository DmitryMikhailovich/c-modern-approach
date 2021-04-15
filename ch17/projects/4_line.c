#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "4_line.h"

#define MAX_LINE_LEN 60

struct word_node {
    const char *word;
    struct word_node *next;
};

struct word_node *line = NULL;
int line_len = 0;
int num_words = 0;

void clear_line(void) {
    struct word_node *prev, *cur;
    cur = line; 
    while(cur != NULL) {
        prev = cur;
        cur = cur->next;    
        free(prev);
    } 
    line = NULL;
    line_len = 0;
    num_words = 0;
}

void add_word(const char *word) {
    char *new_word = malloc(sizeof(word));
    struct word_node *last;
    struct word_node *w = malloc(sizeof(struct word_node));
    strcpy(new_word, word);
    w->word = new_word;
    w->next = NULL;
    if(line == NULL) {
        line = w;
    } else {
        for (last = line; last != NULL && last->next != NULL; last = last->next)
            ;
        last->next = w;
    }
    if(num_words > 0)
        line_len++;
    line_len += strlen(word);
    num_words++;
}

int space_remaining(void) {
    return MAX_LINE_LEN - line_len;
}

void write_line(void) {
    struct word_node *w;
    int extra_spaces, spaces_to_insert, i, j;

    extra_spaces = MAX_LINE_LEN - line_len;
    for(w = line; w != NULL; w = w->next) { 
        printf("%s", w->word);
        if(w->next == NULL)
            continue;
        spaces_to_insert = extra_spaces / (num_words - 1);
        for(j = 1; j <= spaces_to_insert + 1; j++)
            putchar(' ');
        extra_spaces -= spaces_to_insert;
        num_words--;
    }
    putchar('\n');
}

void flush_line(void) {
    printf("in flush line\n");
    struct word_node *w;
    if(line_len > 0)
        for(w = line; w != NULL; w = w->next) {
            puts(w->word);
            if(w->next != NULL)
                putchar(' ');
        }
}
