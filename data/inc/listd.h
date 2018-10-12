#ifndef LISTD_H
#define LISTD_H

#include <stdbool.h>

struct Listd
{
    struct Listd *prev, *next;
    void *data;
};

bool listd_search(struct Listd **list, void *data, bool (*equals)(void *, void *));

void listd_pushFront(struct Listd **list, void *data);

void listd_pushBack(struct Listd **list, void *data);

void listd_next(struct Listd **list);

void listd_prev(struct Listd **list);

bool listd_hasNext(struct Listd *list);

bool listd_hasPrev(struct Listd *list);

void listd_first(struct Listd **list);

void listd_last(struct Listd **list);

void *listd_retrieve(struct Listd *list);

void listd_remove(struct Listd **list);

unsigned int listd_size(struct Listd *list);

bool listd_isEmpty(struct Listd *list);

#endif
