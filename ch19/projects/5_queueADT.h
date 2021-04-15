#ifndef QUEUE_H
#define QUEUE_H
#include <stdbool.h>

typedef int Item;
typedef struct queue_type *Queue;

Queue create();
void insert(Queue q, Item i);
Item remove_item(Queue q);
Item return_first(Queue q);
Item return_last(Queue q);
bool is_empty(Queue q);
void destroy(Queue q);
void make_empty(Queue q);

#endif
