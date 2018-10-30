#ifndef LISTD_H
#define LISTD_H

#include "node.h"
#include <stdbool.h>

/*
 * Listd
 * *****
 * A dynamic doubly linked list. To use this datastructure, allocate the Listd
 * struct and init with the init function. When done with the queue, be sure to
 * pop the list until it's empty. This list is a wrapper around the node.h node
 * struct. If necessary, please do implement functions which manipulates the
 * linked list directly. This list is a doubly linked list and generic. Any
 * type of datastructure can be referenced to be copied into the list. For
 * larger datastructures, storing a pointer to this datastructure is adviced.
 * Small datastructures can be copied directly to avoid the overhead of the
 * saved pointer.
 */
struct Listd
{
    struct Node *head, *tail;
    unsigned int structsize;
};

/*
 * listd_init()
 * ************
 * Initiate the listd datastructure. This function expect a reference to an
 * already allocated structure. And the sizeof the structure which will be
 * pushed into the list.
 *
 * Complexity:
 * O(1)
 *
 * @param list        - A reference to a listd.
 *
 * @param structsize  - The size of the datastructure which will be copied to
 *                      nodes when adding.
 *
 * @return            - void
 */
void listd_init(struct Listd *list, unsigned int structsize);

/*
 * listd_pushFront()
 * *****************
 * Push a node with the passed data as the new front of the list.
 *
 * Complexity:
 * O(1)
 *
 * @param list        - A reference to a listd.
 *
 * @param data        - A pointer to the datastructure which will be copied to
 *                      the added node.
 *
 * @return            - void
 */
void listd_pushFront(struct Listd *list, const void *data);

/*
 * listd_pushBack()
 * ****************
 * Push a node with the passed data as the new back of the list.
 *
 * Complexity:
 * O(1)
 *
 * @param list        - A reference to a listd.
 *
 * @param data        - A pointer to the datastructure which will be copied to
 *                      the added node.
 *
 * @return            - void
 */
void listd_pushBack(struct Listd *list, const void *data);

/*
 * listd_peekFront()
 * *****************
 * Peek at the data the front node of the list holds. No checks for an empty
 * list.
 *
 * Complexity:
 * O(1)
 *
 * @param list        - A reference to a listd.
 *
 * @param data        - A buffer in which the data the front node holds will be
 *                      stored.
 *
 * @return            - void
 */
void listd_peekFront(const struct Listd *list, void *data);

/*
 * listd_peekBack()
 * ****************
 * Peek at the data the last node of the list holds. No checks for an empty
 * list.
 *
 * Complexity:
 * O(1)
 *
 * @param list        - A reference to a listd.
 *
 * @param data        - A buffer in which the data the last node holds will be
 *                      stored.
 *
 * @return            - void
 */
void listd_peekBack(const struct Listd *list, void *data);

/*
 * listd_popFront()
 * ****************
 * Removes the front node from the list and returns its data. No checks for an
 * empty list.
 *
 * Complexity:
 * O(1)
 *
 * @param list        - A reference to a listd.
 *
 * @param data        - A buffer in which the data the previous front node held
 *                      will be stored.
 *
 * @return            - void
 */
void listd_popFront(struct Listd *list, void *data);

/*
 * listd_popBack()
 * ***************
 * Removes the last node from the list and returns its data. No checks for an
 * empty list.
 *
 * Complexity:
 * O(1)
 *
 * @param list        - A reference to a listd.
 *
 * @param data        - A buffer in which the data the previous last node held
 *                      will be stored.
 *
 * @return            - void
 */
void listd_popBack(struct Listd *list, void *data);

/*
 * listd_size()
 * ************
 * Returns the current number of elements in the list.
 *
 * Complexity:
 * O(n)
 *
 * @param list        - A reference to a listd.
 *
 * @return            - The size of the list.
 */
unsigned int listd_size(const struct Listd *list);

/*
 * listd_structsize()
 * ******************
 * Returns the size of the structs stored in the list.
 *
 * Complexity:
 * O(1)
 *
 * @param list        - A reference to a listd.
 *
 * @return            - The size of the list.
 */
unsigned int listd_structsize(const struct Listd *list);

/*
 * listd_isEmpty()
 * ***************
 * Returns true if the list is empty.
 *
 * Complexity:
 * O(1)
 *
 * @param list        - A reference to a listd.
 *
 * @return            - Returns true if the list does not contain any elements.
 */
bool listd_isEmpty(const struct Listd *list);

#endif
