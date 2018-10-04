#include "stacks.h"
#include <stdlib.h>
#include <stddef.h>

void stacks_init(struct Stacks *stack, unsigned int capacity)
{
    stack->size = 0;
    stack->capacity = capacity;
    stack->data = malloc(capacity * sizeof(void *));
}

void stacks_push(struct Stacks *stack, void *data)
{
    stack->data[stack->size++] = data;
}

void *stacks_pop(struct Stacks *stack)
{
    return stack->data[--stack->size];
}

void *stacks_peek(struct Stacks *stack)
{
    return stack->data[stack->size - 1];
}

unsigned int stacks_capacity(struct Stacks *stack)
{
    return stack->capacity;
}

unsigned int stacks_size(struct Stacks *stack)
{
    return stack->size;
}

void stacks_destroy(struct Stacks *stack)
{
    free(stack->data);
}
