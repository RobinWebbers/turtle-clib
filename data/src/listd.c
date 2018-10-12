#include "listd.h"
#include <stdlib.h>

bool listd_search(struct Listd **list, void *data, bool (*equals)(void *, void *))
{
    struct Listd *curr;

    if(*list == NULL)
        return false;

    curr = *list;

    if(equals((**list).data, data))
        return true;

    while(listd_hasPrev(*list))
    {
        listd_prev(list);
        if(equals((**list).data, data))
            return true;
    }

    *list = curr;

    while(listd_hasNext(*list))
    {
        listd_next(list);
        if(equals((**list).data, data))
            return true;
    }
    *list = curr;
    return false;
}

void listd_pushFront(struct Listd **list, void *data)
{
    struct Listd *push = malloc(sizeof(struct Listd));
    push->data = data;

    if(listd_isEmpty(*list))
    {
        *list = push;
        push->next = NULL;
        push->prev = NULL;
        return;
    }

    if(listd_hasNext(*list))
        (**list).next->prev = push;
    push->next = (**list).next;
    (**list).next = push;
    push->prev = *list;
}

void listd_pushBack(struct Listd **list, void *data)
{
    struct Listd *push = malloc(sizeof(struct Listd));

    if(listd_isEmpty(*list))
    {
        *list = push;
        (**list).next = NULL;
        (**list).prev = NULL;
        return;
    }

    if(listd_hasPrev(*list))
        (**list).prev->next = push;
    push->prev = (**list).prev;
    (**list).prev = push;
    push->next = *list;
}

void listd_next(struct Listd **list)
{
    *list = (**list).next;
}

void listd_prev(struct Listd **list)
{
    *list = (**list).prev;
}

bool listd_hasNext(struct Listd *list)
{
    return list->next != NULL;
}

bool listd_hasPrev(struct Listd *list)
{
    return list->prev != NULL;
}

void listd_first(struct Listd **list)
{
    if(*list == NULL)
        return;
    while((**list).prev != NULL)
    {
        listd_prev(list);
    }
}

void listd_last(struct Listd **list)
{
    if(*list == NULL)
        return;
    while((**list).next != NULL)
    {
        listd_next(list);
    }
}

void *listd_retrieve(struct Listd *list)
{
    return list->data;
}

void listd_remove(struct Listd **list)
{
    struct Listd *temp;
    temp = *list;

    if((**list).prev != NULL)
        (**list).prev->next = (**list).next;

    if((**list).next != NULL)
    {
        (**list).next->prev = (**list).prev;
        *list = (**list).next;
    }
    else
    {
        *list = (**list).prev;
    }
    free(temp);
}

unsigned int listd_size(struct Listd *list)
{
    unsigned int size = 0;

    listd_first(&list);
    while(list != NULL)
    {
        listd_next(&list);
        size++;
    }
    return size;
}

bool listd_isEmpty(struct Listd *list)
{
    return list == NULL;
}
