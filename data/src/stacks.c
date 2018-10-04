#include "stacks.h"
#include <stdlib.h>
#include <stddef.h>

void init_stacks(struct Stacks *stack, size_t nitems, size_t size)
{
    stack->top = 0;
    stack->nitems = nitems;
    stack->size = size;
    stack->data = malloc(size * nitems);
}

void stacks_push(struct Stacks *stack, void *data)
{
    char *src = data;
    char *dest = stack->data;
    dest += stack->size * stack->top++;
    for(int i = 0;  i < stack->size; i++)
        dest[i] = src[i];
}

void *stacks_pop(struct Stacks *stack)
{
    char *data = stack->data;
    return &data[--stack->top * stack->size];
}

void *stacks_peek(struct Stacks *stack)
{
    char *data = stack->data;
    return &data[stack->top * stack->size];
}

size_t stacks_nitems(struct Stacks *stack)
{
    return stack->nitems;
}

size_t stacks_size(struct Stacks *stack)
{
    return stack->size;
}

size_t stacks_top(struct Stacks *stack)
{
    return stack->top;
}

void destroy_stacks(struct Stacks *stack)
{
    free(stack->data);
}
