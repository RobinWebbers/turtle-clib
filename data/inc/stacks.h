#ifndef STACKS_H
#define STACKS_H

#include <stddef.h>

struct Stacks
{
    size_t nitems;
    size_t size;
    size_t top;
    void *data;
};

void init_stacks(struct Stacks *stack, size_t nitems, size_t size);

void stacks_push(struct Stacks *stack, void *data);

void *stacks_pop(struct Stacks *stack);

void *stacks_peek(struct Stacks *stack);

size_t stacks_nitems(struct Stacks *stack);

size_t stacks_size(struct Stacks *stack);

size_t stacks_top(struct Stacks *stack);

void destroy_stacks(struct Stacks *stack);

#endif
