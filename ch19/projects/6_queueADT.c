#include <stdlib.h>
#include <stdio.h>
#include "6_queueADT.h"


struct queue_type {
    int first_empty;
    int next_removed;
    int count;
    Item *content;
    int size;
};

Queue create(int size) {
    struct queue_type *q = malloc(sizeof(struct queue_type));
    q->content = malloc(size * sizeof(Item));
    q->first_empty = 0;
    q->next_removed = 0;
    q->count = 0;
    q->size = size;
    return q;
}

void insert(Queue q, Item i) {
    q->content[q->first_empty++] = i;
    if(q->first_empty == q->size) {
        q->first_empty = 0;
    }
    q->count++;
}

Item remove_item(Queue q) {
    Item v = q->content[q->next_removed];
    q->content[q->next_removed++] = 0;
    if(q->next_removed == q->size) {
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
        return q->content[q->size-1];
    else
        return q->content[q->first_empty-1];
}

bool is_empty(Queue q) {
    return 0 == q->count;
}

void destroy(Queue q) {
    free(q->content);
    free(q);
}

void make_empty(Queue q) {
    q->first_empty = 0;
    q->next_removed = 0;
    q->count = 0;

}
