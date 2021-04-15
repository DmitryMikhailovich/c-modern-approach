#ifndef QUEUE_H
#define QUEUE_H
#include <stdbool.h>

#define MAX_SIZE 100

typedef int Item;
typedef struct  {
    int first_empty;
    int next_removed;
    int count;
    Item content[MAX_SIZE];
} Queue;

Queue *create();
void insert(Queue *q, Item i);
Item remove_item(Queue *q);
Item return_first(Queue *q);
Item return_last(Queue *q);
bool is_empty(Queue *q);

#endif
