#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

struct node {
    Item content;
    struct node *next;
};

struct queue_type {
    struct node *first;
    struct node *last;
};

Queue create() {
    struct queue_type *q = malloc(sizeof(struct queue_type));
    if(q == NULL) {
        printf("Failed to allocate memory for Queue\n");
        exit(EXIT_FAILURE);
    }
    return q;
}

void insert(Queue q, Item i) {
    struct node *new_node = malloc(sizeof(struct node));
    if(new_node == NULL) {
        printf("Failed to allocate memory for Node\n");
        exit(EXIT_FAILURE);
    }
    if(q->last == NULL) {
        q->last = new_node;
    } else {
        q->last->next = new_node;
        q->last = new_node;
    }
}

Item remove_item(Queue q) {
    if(q->last == NULL) {
        printf("Queue is empty\n");
        exit(EXIT_FAILURE);
    }
    struct node *last = q->last;
    struct node *cur_node; 
    for(cur_node = q->first; cur_node->next != last; cur_node = cur_node->next)
        ;
    cur_node->next = NULL;

    Item v = last->content;
    free(last);
    return v;
}

Item return_first(Queue q) {
    if(q->last == NULL) {
        printf("Queue is empty.\n");
        exit(EXIT_FAILURE);
    }
    return q->first->content;
}

Item return_last(Queue q) {
    if(q->last == NULL) {
        printf("Queue is empty.\n");
        exit(EXIT_FAILURE);
    }
    return q->last->content;
}

bool is_empty(Queue q) {
    return q->first == NULL;
}
