#include "queues.h"
#include <stdlib.h>

void queues_init(struct Queues *queue, unsigned int capacity)
{
    queue->head = 0;
    queue->tail = 0;
    queue->size = 0;
    queue->capacity = capacity;
    queue->data = malloc(capacity * sizeof(void *));
}

void queues_enqueue(struct Queues *queue, void *data)
{
    queue->size++;
    queue->tail = (queue->tail + 1) % queue->capacity;
    queue->data[queue->tail] = data;
}

void *queues_dequeue(struct Queues *queue)
{
    queue->size--;
    queue->head = (queue->head + 1) % queue->capacity;
    return queue->data[queue->head];
}

void *queues_peek(struct Queues *queue)
{
    return queue->data[(queue->head + 1) % queue->capacity];
}

unsigned int queues_capacity(struct Queues *queue)
{
    return queue->capacity;
}

unsigned int queues_size(struct Queues *queue)
{
    return queue->size;
}

void queues_destroy(struct Queues *queue)
{
    free(queue->data);
}
