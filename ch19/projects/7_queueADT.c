#include <stdlib.h>
#include <stdio.h>
#include "7_queueADT.h"

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
    new_node->content = i;
    new_node->next = NULL;
    if(q->last == NULL) {
        q->first = new_node;
        q->last = new_node;
    } else {
        if(q->first == q->last) {
            q->first->next = new_node;
            q->last = new_node;
        } else {
            q->last->next = new_node;
            q->last = new_node;
        }
    }
}

Item remove_item(Queue q) {
    if(q->last == NULL) {
        printf("Queue is empty\n");
        exit(EXIT_FAILURE);
    }
    struct node *last = q->last;
    Item v = last->content;
    if(q->first == q->last) {
        q->first = NULL;
        q->last = NULL;
        free(last);
        return v;
    }
    
    struct node *pre_last; 
    for(pre_last = q->first; pre_last != NULL && pre_last->next != last; pre_last = pre_last->next)
        ;
    pre_last->next = NULL;
    q->last = pre_last;

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

void make_empty(Queue q) {
    struct node *first, *second;
    while(!is_empty(q)) {
        first = q->first;
        second = first->next;
        q->first = second;
        free(first);
    }
}

void destroy(Queue q) {
    make_empty(q);
    free(q);
}
