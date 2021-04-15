#include <stdlib.h>
#include <stdio.h>
#include "5_queue.h"


Queue *create() {
    Queue *q = malloc(sizeof(Queue));
    q->count = 0;
    return q;
}

void insert(Queue *q, Item i) {
    q->content[q->first_empty++] = i;
    if(q->first_empty == MAX_SIZE) {
        q->first_empty = 0;
    }
    q->count++;
}

Item remove_item(Queue *q) {
    Item v = q->content[q->next_removed];
    q->content[q->next_removed++] = 0;
    if(q->next_removed == MAX_SIZE) {
        q->next_removed = 0;
    }
    q->count--;

    return v;
}

Item return_first(Queue *q) {
    return q->content[q->next_removed];
}

Item return_last(Queue *q) {
    if(q->first_empty == 0)
        return q->content[MAX_SIZE-1];
    else
        return q->content[q->first_empty-1];
}

bool is_empty(Queue *q) {
    return 0 == q->count;
}
