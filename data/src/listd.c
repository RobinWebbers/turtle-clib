#include "listd.h"
#include <stdlib.h>
#include <string.h>

void listd_init(struct Listd *list, unsigned int structsize)
{
    list->head = NULL;
    list->tail = NULL;
    list->structsize = structsize;
}

void listd_pushFront(struct Listd *list, const void *data)
{
    struct Node *insert = malloc(sizeof(struct Node) + list->structsize);
    memcpy(insert + 1, data, list->structsize);

    if(list->head == NULL)
    {
        insert->next = NULL;
        insert->prev = NULL;
        list->tail = insert;
    }
    else
    {
        insert->next = list->head;
        insert->prev = NULL;
        list->head->prev = insert;
    }
    list->head = insert;
}

void listd_pushBack(struct Listd *list, const void *data)
{
    struct Node *insert = malloc(sizeof(struct Node) + list->structsize);
    memcpy(insert + 1, data, list->structsize);

    if(list->tail == NULL)
    {
        insert->next = NULL;
        insert->prev = NULL;
        list->head = insert;
    }
    else
    {
        insert->next = NULL;
        insert->prev = list->tail;
        list->tail->next = insert;
    }
    list->tail = insert;
}

void listd_peekFront(const struct Listd *list, void *data)
{
    memcpy(data, list->head + 1, list->structsize);
}

void listd_peekBack(const struct Listd *list, void *data)
{
    memcpy(data, list->tail + 1, list->structsize);
}

void listd_popFront(struct Listd *list, void *data)
{
    struct Node *del;
    del = list->head;
    memcpy(data, list->head + 1, list->structsize);

    if(del->next != NULL)
    {
        list->head = del->next;
        list->head->prev = NULL;
    }
    else
    {
        list->head = NULL;
        list->tail = NULL;
    }

    free(del);
}

void listd_popBack(struct Listd *list, void *data)
{
    struct Node *del;
    del = list->tail;
    memcpy(data, list->tail + 1, list->structsize);

    if(del->prev != NULL)
    {
        list->tail = del->prev;
        list->tail->next = NULL;
    }
    else
    {
        list->head = NULL;
        list->tail = NULL;
    }

    free(del);
}

unsigned int listd_size(const struct Listd *list)
{
    unsigned int size = 0;
    for(struct Node *node = list->head; node != NULL; node = node->next)
    {
        size++;
    }
    return size;
}

unsigned int listd_structsize(const struct Listd *list)
{
    return list->structsize;
}

bool listd_isEmpty(const struct Listd *list)
{
    return list->head == NULL;
}
