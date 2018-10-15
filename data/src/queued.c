#include "queued.h"
#include <string.h>
#include <stdlib.h>

void queued_init(struct Queued *queue, unsigned int structsize)
{
    queue->head = NULL;
    queue->tail = NULL;
    queue->structsize = structsize;
}

void queued_enqueue(struct Queued *queue, const void *data)
{
    if(queue->tail == NULL)
    {
        queue->tail = malloc(sizeof(struct Stackd) + queue->structsize);
        queue->head = queue->tail;
    }
    else
    {
        queue->tail->next = malloc(sizeof(struct Stackd) + queue->structsize);
        queue->tail = queue->tail->next;
    }
    queue->tail->next = NULL;
    memcpy(queue->tail + 1, data, queue->structsize);
}

void queued_dequeue(struct Queued *queue, void *data)
{
    stackd_pop(&(queue->head), data, queue->structsize);
    if(queue->head == NULL)
        queue->tail = NULL;
}

void queued_peek(const struct Queued *queue, void *data)
{
    memcpy(data, queue->head + 1, queue->structsize);
}

void queued_push(struct Queued *queue, const void *data)
{
    stackd_push(&(queue->head), data, queue->structsize);
    if(queue->tail == NULL)
        queue->tail = queue->head;
}

void queued_peekLast(const struct Queued *queue, void *data)
{
    memcpy(data, queue->tail + 1, queue->structsize);
}

unsigned int queued_size(const struct Queued *queue)
{
    return stackd_size(queue->head);
}

bool queued_isEmpty(const struct Queued *queue)
{
    return queue->tail == NULL;
}

void queued_reverse(struct Queued *queue)
{
    queue->tail = queue->head;
    stackd_reverse(&(queue->head));
}

void queued_insert(struct Queued *queue, const void *data, int index)
{
    stackd_insert(&(queue->head), data, queue->structsize, index);
    if(queue->tail == NULL)
        queue->tail = queue->head;
    else if(queue->tail->next != NULL)
        queue->tail = queue->tail->next;
}

void queued_remove(struct Queued *queue, void *data, int index)
{
    //del is also used as previously accessed node to adjust the tail when
    //removing the last item in the queue. This is done before deleting.
    struct Stackd **curr, *del;
    del = NULL;
    curr = &(queue->head);

    for(int i = 0; i < index; i++)
    {
        del = *curr;
        curr = &((**curr).next);
    }

    if(queue->tail == *curr)
        queue->tail = del;

    del = *curr;
    *curr = del->next;
    memcpy(data, del + 1, queue->structsize);
    free(del);
}
