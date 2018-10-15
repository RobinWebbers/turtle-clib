#include "stacks.h"
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>

void stacks_init(struct Stacks *stack, unsigned int capacity, unsigned int structsize)
{
    stack->size = 0;
    stack->capacity = capacity;
    stack->structsize = structsize;
    stack->data = malloc(capacity * structsize);
}

void stacks_push(struct Stacks *stack, const void *data)
{
    memcpy(stack->data + stack->structsize * stack->size++, data, stack->structsize);
}

void stacks_pop(struct Stacks *stack, void *data)
{
    memcpy(data, stack->data + stack->structsize * --stack->size, stack->structsize);
}

void stacks_peek(const struct Stacks *stack, void *data)
{
    memcpy(data, stack->data + stack->structsize * (stack->size - 1), stack->structsize);
}

unsigned int stacks_capacity(const struct Stacks *stack)
{
    return stack->capacity;
}

unsigned int stacks_size(const struct Stacks *stack)
{
    return stack->size;
}

unsigned int stacks_structsize(const struct Stacks *stack)
{
    return stack->structsize;
}

void stacks_destroy(struct Stacks *stack)
{
    free(stack->data);
}
