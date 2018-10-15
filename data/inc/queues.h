#ifndef QUEUES_H
#define QUEUES_H

/*
 * Queues
 * ******
 * A static queue. To use this datastructure, allocate the Queued struct and
 * init the queue. Destroy the queue when you are not using it and there are no
 * more malloced structures in there that can otherwise not be freed. Any type
 * of datastructure can be referenced to be copied onto the stack. For larger
 * datastructures, storing a pointer to this datastructure is adviced. Small
 * datastructures can be copied directly to avoid the overhead of the saved
 * pointer.
 */
struct Queues
{
    unsigned int head, tail, capacity, size, structsize;
    void *data;
};

/*
 * queues_init()
 * *************
 * Initiate the queue with the desired capacity. This function must be called
 * for the static queue to work correctly.
 *
 * Complexity:
 * O(1)
 *
 * @param queue       - A reference to the queues of the user.
 *
 * @param capacity    - The maximum number of elements in the queue.
 *
 * @param structsize  - The size of the datastructure which will be copied into
 *                      the stack.
 *
 * @return            - void
 */
void queues_init(struct Queues *queue, unsigned int capacity, unsigned int structsize);

/*
 * queues_enqueue()
 * ****************
 * Enqueue an element to the tail of the queue. This function has no bounds
 * checking.
 *
 * Complexity:
 * O(1)
 *
 * @param queue       - A reference to the queues of the user.
 *
 * @param data        - A pointer to the datastructure to be enqueued.
 *
 * @return            - void
 */
void queues_enqueue(struct Queues *queue, const void *data);

/*
 * queues_dequeue()
 * ****************
 * Dequeue an element from the head of the queue. This function has no bounds
 * checking.
 *
 * Complexity:
 * O(1)
 *
 * @param queue       - A reference to the queues of the user.
 *
 * @param data        - A buffer into which the data from the dequeued element
 *                      is copied.
 *
 * @return            - void
 */
void queues_dequeue(struct Queues *queue, void *data);

/*
 * queues_peek()
 * *************
 * Peek at the next element to be dequeued from the queue. This function has no
 * bounds checking.
 *
 * Complexity:
 * O(1)
 *
 * @param queue       - A reference to the queues of the user.
 *
 * @param data        - A buffer into which the data from the top element is
 *                      copied.
 *
 * @return            - void
 */
void queues_peek(const struct Queues *queue, void *data);

/*
 * queues_capacity()
 * *****************
 * Returns the maximum amount of elements that can be in the queue at once.
 *
 * Complexity:
 * O(1)
 *
 * @param queue       - A reference to the queues of the user.
 *
 * @return            - The capacity of the queue.
 */
unsigned int queues_capacity(const struct Queues *queue);

/*
 * queues_size()
 * *************
 * Returns the amount of elements currently in the queue.
 *
 * Complexity:
 * O(1)
 *
 * @param queue       - A reference to the queues of the user.
 *
 * @return            - The size of the queue.
 */
unsigned int queues_size(const struct Queues *queue);

/*
 * queues_structsize()
 * *******************
 * Returns the size of the elements stored in the queue.
 *
 * Complexity:
 * O(1)
 *
 * @param queue       - A reference to the queues of the user.
 *
 * @return            - The size of the structs in the queue.
 */
unsigned int queues_structsize(const struct Queues *queue);

/*
 * queues_destroy()
 * ****************
 * Frees the array in which the elements are stored.
 *
 * Complexity:
 * O(1)
 *
 * @param queue       - A reference to the queues of the user.
 *
 * @return            - void
 */
void queues_destroy(struct Queues *queue);

#endif
