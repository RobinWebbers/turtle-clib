#ifndef QUEUED_H
#define QUEUED_H

#include "stackd.h"
#include <stdbool.h>

/*
 * Queued
 * ******
 * A dynamic queue. To use this datastructure, allocate the Queued struct and
 * init the queue. There is no need to destroy the stack, you should make sure
 * to empty the queue if there are malloced elements in there. The queue is
 * singly linked and generic.
 */
struct Queued
{
    struct Stackd *head, *tail;
};

/*
 * queued_init()
 * *************
 * Initiate the queue datastructure. This function expect a reference to an
 * already allocated structure.
 *
 * Complexity:
 * O(1)
 *
 * @param queue       - A reference to a queue.
 *
 * @return            - void
 */
void queued_init(struct Queued *queue);

/*
 * queued_enqueue()
 * ****************
 * Enqueue a pointer to a datastructure to the tail of the queue.
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
void queued_enqueue(struct Queued *queue, void *data);

/*
 * queued_dequeue()
 * ****************
 * Dequeue a pointer to a datastructure from the head of the queue.
 *
 * Complexity:
 * O(1)
 *
 * @param queue       - A pointer to an initialized queue.
 *
 * @return            - A pointer to a datastructure held by the removed node.
 */
void *queued_dequeue(struct Queued *queue);

/*
 * queued_peek()
 * *************
 * Peek at the next pointer to a datastructure to be dequeued from the head of
 * the queue.
 *
 * Complexity:
 * O(1)
 *
 * @param queue       - A pointer to an initialized queue.
 *
 * @return            - A pointer to a datastructure held by the head of the
 *                      queue.
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
 * @param data        - A pointer to a datastructure to be added to the queue.
 *
 * @return            - void
 */
void queued_push(struct Queued *queue, void *data);

/*
 * queued_peekl()
 * **************
 * Peek at the last pointer to a datastructure to be dequeued from the head of
 * the queue. This is the tail of the queue.
 *
 * Complexity:
 * O(1)
 *
 * @param queue       - A pointer to an initialized queue.
 *
 * @return            - A pointer to a datastructure held by the tail of the
 *                      queue.
 */
void *queued_peekl(struct Queued *queue);

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
unsigned int queued_size(struct Queued *queue);

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
bool queued_isEmpty(struct Queued *queue);

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
void queued_insert(struct Queued *queue, void *data, int index);

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
void *queued_remove(struct Queued *queue, int index);

#endif
