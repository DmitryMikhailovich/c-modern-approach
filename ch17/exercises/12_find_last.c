#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};

struct node *find_last(struct node *list, int n);

int main(void) {

    return 0;
}


struct node *find_last(struct node *list, int n) {
    struct node *p, *last = NULL;
    for (p = list; p != NULL; p = list->next)
        if (p->value == n)
            last = p;
    return last;
}
    
