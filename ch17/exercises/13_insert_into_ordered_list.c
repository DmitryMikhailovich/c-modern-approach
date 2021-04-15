#include <stdlib.h>
#include <stdio.h>

struct node {
    int value;
    struct node *next;
};

struct node *insert_into_ordered_list(struct node *list, struct node *new_node);

int main(void) {

    return 0;
}

struct node *insert_into_ordered_list(struct node *list,
                                      struct node *new_node) {
    struct node *cur = list, *prev = NULL;
    if (list == NULL)
        return new_node;
    while (cur != NULL && cur->value <= new_node->value) {
        prev = cur;
        cur = cur->next;
    }
    if (cur == NULL)
        prev->next = new_node;
    else { 
        prev->next = new_node;
        new_node->next = cur;
    }
    return list;
}

