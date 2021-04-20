#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "3_stackADT2.h"

struct stack_type {
    Item *contents;
    int top;
    int size;
};


Stack create(int size) {
    Stack s = malloc(sizeof(struct stack_type));
    assert(s != NULL);

    s->contents = malloc(size * sizeof(Item));
    assert(s->contents != NULL);

    s->top = 0;
    s->size = size;
    return s;
}

void destroy(Stack s) {
    free(s->contents);
    free(s);
}

void make_empty(Stack s) {
    s->top = 0;
}

bool is_empty(Stack s) {
    return s->top == 0;
}

bool is_full(Stack s) {
    return s->top == s->size;
}

void push(Stack s, Item i) {
    if(is_full(s)) {
        Item *old_contents = s->contents;
        s->size *= 2;
        s->contents = malloc(s->size * sizeof(Item));
        assert(s->contents != NULL);

        for(int i = 0; i <= s->top; i++)
            s->contents[i] = old_contents[i];
        free(old_contents);
    }
    s->contents[s->top++] = i;
}

Item pop(Stack s) {
    assert(!is_empty(s));

    return s->contents[--s->top];
}

Item peek(Stack s) {
    return s->contents[s->top];
}
