#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};

int count_occurrences(struct node *list, int n);

int main(void) {
    struct node *list = malloc(sizeof(struct node));
    list->value = 1;
    list->next = malloc(sizeof(struct node));
    list->next->value = 2;
    printf("Number %d occurred %d times\n", 1, count_occurrences(list, 1)); 
    return 0;
}


int count_occurrences(struct node *list, int n) {
    int count = 0;
    struct node *p;
    for (p = list; p != NULL; p = p->next)
        if (p->value == n)
            count++;
    return count;
}
