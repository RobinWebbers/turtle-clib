#include <string.h>
#include <stdlib.h>
#include "node.h"

void node_insertAfter(struct Node **node, const void *data, unsigned int structsize)
{
    struct Node *insert = malloc(sizeof(struct Node) + structsize);
    memcpy(insert + 1, data, structsize);

    if(*node == NULL)
    {
        insert->next = NULL;
        insert->prev = NULL;
    }
    else
    {
        if((**node).next != NULL)
            (**node).next->prev = insert;
        insert->next = (**node).next;
        insert->prev = *node;
        (**node).next = insert;
    }
    *node = insert;
}

void node_insertBefore(struct Node **node, const void *data, unsigned int structsize)
{
    struct Node *insert = malloc(sizeof(struct Node) + structsize);
    memcpy(insert + 1, data, structsize);

    if(*node == NULL)
    {
        insert->next = NULL;
        insert->prev = NULL;
    }
    else
    {
        if((**node).prev != NULL)
            (**node).prev->next = insert;
        insert->next = *node;
        insert->prev = (**node).prev;
        (**node).prev = insert;
    }
    *node = insert;
}

void node_peek(struct Node *node, void *data, unsigned int structsize)
{
    memcpy(data, node + 1, structsize);
}

void node_remove(struct Node **node)
{
    struct Node *del;
    del = *node;

    if(del->prev != NULL)
        del->prev->next = del->next;

    if(del->next != NULL)
    {
        del->next->prev = del->prev;
        *node = del->next;
    }
    else
        *node = del->prev;

    free(del);
}

void node_first(struct Node **node)
{
    while((**node).prev != NULL)
        *node = (**node).prev;
}

void node_last(struct Node **node)
{
    while((**node).next != NULL)
        *node = (**node).next;
}
