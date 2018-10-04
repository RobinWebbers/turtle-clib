#include "queued.h"
#include "stdlib.h"

void queued_init(struct Queued *queue)
{
    queue->head = NULL;
    queue->tail = NULL;
}

void queued_enqueue(struct Queued *queue, void *data)
{
    if(queue->tail == NULL)
    {
        queue->tail = malloc(sizeof(struct Stackd));
        queue->head = queue->tail;
    }
    else
    {
        queue->tail->next = malloc(sizeof(struct Stackd));
        queue->tail = queue->tail->next;
    }
    queue->tail->next = NULL;
    queue->tail->data = data;
}

void *queued_dequeue(struct Queued *queue)
{
    void *data = stackd_pop(&(queue->head));
    if(queue->head == NULL)
        queue->tail = NULL;
    return data;
}

void *queued_peek(struct Queued *queue)
{
    return queue->head->data;
}

void queued_push(struct Queued *queue, void *data)
{
    stackd_push(&(queue->head), data);
    if(queue->tail == NULL)
        queue->tail = queue->head;
}

void *queued_peekl(struct Queued *queue)
{
    return queue->tail->data;
}

int queued_size(struct Queued *queue)
{
    return stackd_size(queue->head);
}

int queued_isEmpty(struct Queued *queue)
{
    return queue->tail == NULL;
}

void queued_reverse(struct Queued *queue)
{
    queue->tail = queue->head;
    stackd_reverse(&(queue->head));
}

void queued_insert(struct Queued *queue, void *data, int index)
{
    stackd_insert(&(queue->head), data, index);
    if(queue->tail == NULL)
        queue->tail = queue->head;
    else if(queue->tail->next != NULL)
        queue->tail = queue->tail->next;
}

void *queued_remove(struct Queued *queue, int index)
{
    //del is also used as previously accessed node to adjust the tail when
    //removing the last item in the queue. This is done before deleting.
    struct Stackd **curr, *del;
    void *data;
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
    data = del->data;
    free(del);
    return data;
}
