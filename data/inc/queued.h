#ifndef QUEUED_H
#define QUEUED_H

#include "stackd.h"
#include <stdbool.h>

/*
 * Queued
 * ******
 * A dynamic queue. To use this datastructure, allocate the Queued struct and
 * init the queue. To free the memory from the queue, simply dequeue till the
 * queue is empty. This queue is a singly linked list and generic. Any
 * type of datastructure can be referenced to be copied onto the queue. For
 * larger datastructures, storing a pointer to this datastructure is adviced.
 * Small datastructures can be copied directly to avoid the overhead of the
 * saved pointer.
 */
struct Queued
{
    struct Stackd *head, *tail;
    unsigned int structsize;
};

/*
 * queued_init()
 * *************
 * Initiate the queue datastructure. This function expect a reference to an
 * already allocated structure. And the sizeof the structure which will be
 * enqueued.
 *
 * Complexity:
 * O(1)
 *
 * @param queue       - A reference to a queue.
 *
 * @param structsize  - The size of the datastructure which will be copied to
 *                      nodes when adding.
 *
 * @return            - void
 */
void queued_init(struct Queued *queue, unsigned int structsize);

/*
 * queued_enqueue()
 * ****************
 * Enqueue a datastructure to the tail of the queue.
 *
 * Complexity:
 * O(1)
 *
 * @param queue       - A pointer to an initialized queue.
 *
 * @param data        - A pointer to the datastructure to be enqueued to the
 *                      queue.
 *
 * @return            - void
 */
void queued_enqueue(struct Queued *queue, const void *data);

/*
 * queued_dequeue()
 * ****************
 * Dequeue a datastructure from the head of the queue.
 *
 * Complexity:
 * O(1)
 *
 * @param queue       - A pointer to an initialized queue.
 *
 * @param data        - A pointer to a buffer to which the stored data will be
 *                      copied.
 *
 * @return            - void
 */
void queued_dequeue(struct Queued *queue, void *data);

/*
 * queued_peek()
 * *************
 * Peek at the next pointer to a datastructure to be dequeued from the head of
 * the queue. This pointer can be made invalid upon removing the node which
 * carries this data. Please copy it if persistent usage is needed.
 *
 * Complexity:
 * O(1)
 *
 * @param queue       - A pointer to an initialized queue.
 *
 * @return            - Returns a pointer to the datastructure the head holds.
 */
void *queued_peek(struct Queued *queue);

/*
 * queued_push()
 * *************
 * Push a pointer to a datastructure to the head of the queue.
 *
 * Complexity:
 * O(1)
 *
 * @param queue       - A pointer to an initialized queue.
 *
 * @param data        - A pointer to the datastructure to be pushed to the
 *                      queue.
 *
 * @return            - void
 */
void queued_push(struct Queued *queue, const void *data);

/*
 * queued_peekLast()
 * *****************
 * Peek at the last pointer to a datastructure to be dequeued from the head of
 * the queue. This is the tail of the queue. This pointer can be made invalid
 * upon removing the node which carries this data. Please copy it if persistent
 * usage is needed.
 *
 * Complexity:
 * O(1)
 *
 * @param queue       - A pointer to an initialized queue.
 *
 * @return            - Returns a pointer to the datastructure the tail holds.
 */
void *queued_peekLast(struct Queued *queue);

/*
 * queued_size()
 * *************
 * Returns the current number of elements in the queue.
 *
 * Complexity:
 * O(n)
 *
 * @param queue       - A pointer to an initialized queue.
 *
 * @return            - Number of elements in the queue.
 */
unsigned int queued_size(const struct Queued *queue);

/*
 * queued_isEmpty()
 * ****************
 * Returns true when the queue has no elements in it.
 *
 * Complexity:
 * O(1)
 *
 * @param queue       - A pointer to an initialized queue.
 *
 * @return            - Returns true if the queue is empty.
 */
bool queued_isEmpty(const struct Queued *queue);

/*
 * queued_structsize()
 * *******************
 * Returns the size of the elements stored in the queue.
 *
 * Complexity:
 * O(1)
 *
 * @param queue       - A reference to the queued of the user.
 *
 * @return            - The size of the structs in the queue.
 */
unsigned int queued_structsize(const struct Queued *queue);

/*
 * queued_reverse()
 * ****************
 * Reverse the order of the queue.
 *
 * Complexity:
 * O(n)
 *
 * @param queue       - A pointer to an initialized queue.
 *
 * @return            - Number of elements in the queue.
 */
void queued_reverse(struct Queued *queue);

/*
 * queued_insert()
 * ***************
 * Insert a pointer to a datastructure in the queue at the given index, starting
 * from the head of the queue. This function has no bounds checking.
 *
 * Complexity:
 * O(index)
 *
 * @param queue       - A pointer to an initialized queue.
 *
 * @param data        - A pointer to the data to be added.
 *
 * @param index       - The index at which the element should be inserted.
 *                      starting from the head of the queue.
 *
 * @return            - void
 */
void queued_insert(struct Queued *queue, const void *data, int index);

/*
 * queued_remove()
 * ***************
 * Remove a pointer from the datastructure in the queue at the given index,
 * starting from the head of the queue. This function has no bounds checking.
 *
 * Complexity:
 * O(index)
 *
 * @param queue       - A pointer to an initialized queue.
 *
 * @param index       - The index at which the element should be removed.
 *                      starting from the head of the queue.
 *
 * @return            - A pointer to a datastructure held by the removed node.
 */
void queued_remove(struct Queued *queue, void *data, int index);

#endif
