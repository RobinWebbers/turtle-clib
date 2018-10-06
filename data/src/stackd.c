#include "stackd.h"
#include <stdlib.h>

void stackd_push(struct Stackd **stack, void *data)
{
    struct Stackd *top;
    top = malloc(sizeof(struct Stackd));
    top->next = *stack;
    top->data = data;
    *stack = top;
}

void *stackd_pop(struct Stackd **stack)
{
    struct Stackd *top;
    void *data;
    top = *stack;
    data = (**stack).data;
    *stack = (**stack).next;
    free(top);
    return data;
}

void *stackd_peek(struct Stackd *stack)
{
    return stack->data;
}

unsigned int stackd_size(struct Stackd *stack)
{
    int size = 0;
    for(; stack != NULL; stack = stack->next)
        size++;
    return size;
}

void stackd_reverse(struct Stackd **stack)
{
    struct Stackd *prev, *next;

    prev = NULL;
    next = *stack;
    *stack = NULL;

    while(next != NULL)
    {
        prev = *stack;
        *stack = next;
        next = next->next;
        (**stack).next = prev;
    }
}

void stackd_insert(struct Stackd **stack, void *data, unsigned int index)
{
    struct Stackd **curr, *insert;
    curr = stack;

    for(int i = 0; i < index; i++)
        curr = &((**curr).next);

    insert = malloc(sizeof(struct Stackd));
    insert->data = data;
    insert->next = *curr;
    *curr = insert;
}

void *stackd_remove(struct Stackd **stack, unsigned int index)
{
    struct Stackd **curr, *del;
    void *data;
    curr = stack;

    for(int i = 0; i < index; i++)
        curr = &((**curr).next);

    del = *curr;
    *curr = del->next;
    data = del->data;
    free(del);
    return data;
}

void stackd_pushl(struct Stackd **stack, void *data)
{
    struct Stackd **curr, *insert;
    curr = stack;

    while(*curr != NULL)
        curr = &((**curr).next);

    insert = malloc(sizeof(struct Stackd));
    insert->data = data;
    insert->next = NULL;
    *curr = insert;
}

void *stackd_popl(struct Stackd **stack)
{
    struct Stackd **curr;
    void *data;
    curr = stack;

    while((**curr).next != NULL)
        curr = &((**curr).next);

    data = (**curr).data;
    free(*curr);
    *curr = NULL;
    return data;
}

void *stackd_peekl(struct Stackd *stack)
{
    for(; stack->next != NULL; stack = stack->next)
        ;//move to the last node

    return stack->data;
}
