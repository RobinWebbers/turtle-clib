#ifndef LISTD_H
#define LISTD_H

#include <stdbool.h>
#include "node.h"


/*
 WARINING:
 THIS DATASTRUCTURE IS UNDER CONSTRUCTION. THE INTERFACE IS SURE TO CHANGE AND
 THE IMPLEMENTAION HAS NOT YET BEEN TESTED. PLEASE REFRAIN FROM USING THIS.
 */

struct Listd
{
    struct Node *head, *tail;
    unsigned int structsize;
};

void listd_init(struct Listd *list, unsigned int structsize);

void listd_pushFront(struct Listd *list, const void *data);

void listd_pushBack(struct Listd *list, const void *data);

void listd_peekFront(struct Listd *list, void *data);

void listd_peekBack(struct Listd *list, void *data);

void listd_popFront(struct Listd *list, void *data);

void listd_popBack(struct Listd *list, void *data);

unsigned int listd_size(const struct Listd *list);

unsigned int listd_structsize(const struct Listd *list);

bool listd_isEmpty(struct Listd *list);

#endif
