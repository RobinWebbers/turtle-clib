#include "queues.h"
#include <stdlib.h>
#include <string.h>

void queues_init(struct Queues *queue, unsigned int capacity, unsigned int structsize)
{
    queue->head = 0;
    queue->tail = 0;
    queue->size = 0;
    queue->capacity = capacity;
    queue->structsize = structsize;
    queue->data = malloc(capacity * structsize);
}

void queues_enqueue(struct Queues *queue, const void *data)
{
    queue->size++;
    queue->tail = (queue->tail + 1) % queue->capacity;
    memcpy((char *)queue->data + queue->tail * queue->structsize, data, queue->structsize);
}

void queues_dequeue(struct Queues *queue, void *data)
{
    queue->size--;
    queue->head = (queue->head + 1) % queue->capacity;
    memcpy(data, (char *)queue->data + queue->head * queue->structsize, queue->structsize);
}

void queues_peek(const struct Queues *queue, void *data)
{
    memcpy(data, (char *)queue->data + ((queue->head + 1) % queue->capacity) * queue->structsize, queue->structsize);
}

unsigned int queues_capacity(const struct Queues *queue)
{
    return queue->capacity;
}

unsigned int queues_size(const struct Queues *queue)
{
    return queue->size;
}

unsigned int queues_structsize(const struct Queues *queue)
{
    return queue->structsize;
}

void queues_destroy(struct Queues *queue)
{
    free(queue->data);
}
