#include <stdlib.h>
#include <stdio.h>
#include "5_queueADT.h"

#define MAX_SIZE 100

struct queue_type {
    int first_empty;
    int next_removed;
    int count;
    Item content[MAX_SIZE];
};

Queue create() {
    struct queue_type *q = malloc(sizeof(struct queue_type));
    q->first_empty = 0;
    q->next_removed = 0;
    q->count = 0;
    return q;
}

void insert(Queue q, Item i) {
    q->content[q->first_empty++] = i;
    if(q->first_empty == MAX_SIZE) {
        q->first_empty = 0;
    }
    q->count++;
}

Item remove_item(Queue q) {
    Item v = q->content[q->next_removed];
    q->content[q->next_removed++] = 0;
    if(q->next_removed == MAX_SIZE) {
        q->next_removed = 0;
    }
    q->count--;

    return v;
}

Item return_first(Queue q) {
    return q->content[q->next_removed];
}

Item return_last(Queue q) {
    if(q->first_empty == 0)
        return q->content[MAX_SIZE-1];
    else
        return q->content[q->first_empty-1];
}

bool is_empty(Queue q) {
    return 0 == q->count;
}

void destroy(Queue q) {
    free(q);
}

void make_empty(Queue q) {
    q->first_empty = 0;
    q->next_removed = 0;
    q->count = 0;

}
