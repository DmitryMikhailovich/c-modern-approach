#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};

void delete_from_list(struct node **list, int n) {
    struct node *cur, *prev;

    for (cur = *list, prev = NULL;
        cur != NULL && cur->value != n;
        prev = cur, cur = cur->next)
        ;

    if(cur == NULL)
        return;
    if(prev == NULL)
        *list = (*list)->next;
    else
        prev->next = cur->next;

    free(cur);
}

int main(void) {

    struct node *list = malloc(sizeof(struct node));
    list->value = 1;
    list->next = malloc(sizeof(struct node));
    list->next->value = 2;

    delete_from_list(&list, 1);
    printf("First value in list is %d\n", list->value);
    return 0;
}
