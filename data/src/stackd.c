#include "stackd.h"
#include <stdlib.h>
#include <string.h>

void stackd_push(struct Stackd **stack, const void *data, unsigned int structsize)
{
    struct Stackd *top;
    top = malloc(sizeof(struct Stackd) + structsize);
    top->next = *stack;
    memcpy(top + 1, data, structsize);
    *stack = top;
}

void stackd_pop(struct Stackd **stack, void *data, unsigned int structsize)
{
    struct Stackd *top;
    top = *stack;
    memcpy(data, top + 1, structsize);
    *stack = (**stack).next;
    free(top);
}

void stackd_peek(const struct Stackd *stack, void *data, unsigned int structsize)
{
    memcpy(data, stack + 1, structsize);
}

unsigned int stackd_size(const struct Stackd *stack)
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

void stackd_insert(struct Stackd **stack, const void *data, unsigned int structsize, unsigned int index)
{
    struct Stackd **curr, *insert;
    curr = stack;

    for(int i = 0; i < index; i++)
        curr = &((**curr).next);

    insert = malloc(sizeof(struct Stackd) + structsize);
    memcpy(insert + 1, data, structsize);
    insert->next = *curr;
    *curr = insert;
}

void stackd_remove(struct Stackd **stack, void *data, unsigned int structsize, unsigned int index)
{
    struct Stackd **curr, *del;
    curr = stack;

    for(int i = 0; i < index; i++)
        curr = &((**curr).next);

    del = *curr;
    *curr = del->next;
    memcpy(data, del + 1, structsize);
    free(del);
}

void stackd_pushLast(struct Stackd **stack, const void *data, unsigned int structsize)
{
    struct Stackd **curr, *insert;
    curr = stack;

    while(*curr != NULL)
        curr = &((**curr).next);

    insert = malloc(sizeof(struct Stackd) + structsize);
    memcpy(insert + 1, data, structsize);
    insert->next = NULL;
    *curr = insert;
}

void stackd_popLast(struct Stackd **stack, void *data, unsigned int structsize)
{
    struct Stackd **curr;
    curr = stack;

    while((**curr).next != NULL)
        curr = &((**curr).next);

    memcpy(data, *curr + 1, structsize);
    free(*curr);
    *curr = NULL;
}

void stackd_peekLast(const struct Stackd *stack, void *data, unsigned int structsize)
{
    for(; stack->next != NULL; stack = stack->next)
        ;//move to the last node

    memcpy(data, stack + 1, structsize);
}
