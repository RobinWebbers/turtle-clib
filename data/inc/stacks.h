#ifndef STACKS_H
#define STACKS_H

/*
 * Stacks
 * ******
 * A static stack. To use this datastructure, allocate the Stacks struct and
 * init the stack. This sets the capacity of the stack and the type of data to
 * be stored on it. More specifically, the size of the type to be stored on it.
 * When done with the stack, do not forget to destroy it. Any type of
 * datastructure can be referenced to be copied onto the stack. For larger
 * datastructures, storing a pointer to this datastructure is adviced. Small
 * datastructures can be copied directly to avoid the overhead of the saved
 * pointer.
 */
struct Stacks
{
    unsigned int capacity, size, structsize;
    void *data;
};

/*
 * stacks_init()
 * *************
 * Initiate the stack with the desired capacity and size of each element.This
 * function must be called for the static stack to work as intended.
 *
 * Complexity:
 * O(1)
 *
 * @param stack       - A reference to the stacks of the user.
 *
 * @param capacity    - The maximum number of elements on the stack.
 *
 * @param structsize  - The size of the datastructure which will be copied into
 *                      the stack.
 *
 * @return            - void
 */
void stacks_init(struct Stacks *stack, unsigned int capacity, unsigned int structsize);

/*
 * stacks_push()
 * *************
 * Push an element to the top of the stack. This function has no bounds
 * checking.
 *
 * Complexity:
 * O(1)
 *
 * @param stack       - A reference to the stacks of the user.
 *
 * @param data        - Pointer to a datastructure to be pushed onto the stack.
 *
 * @return            - void
 */
void stacks_push(struct Stacks *stack, const void *data);

/*
 * stacks_pop()
 * ************
 * Pop a datastructure from the top of the stack.
 *
 * Complexity:
 * O(1)
 *
 * @param stack       - A reference to the stacks of the user.
 *
 * @param data        - Pointer to a buffer in which the popped data will be
 *                      stored.
 *
 * @return            - A pointer to a datastructure on the top of the stack.
 */
void stacks_pop(struct Stacks *stack, void *data);

/*
 * stacks_peek()
 * *************
 * Peek at the datastructure from the top of the stack.
 *
 * Complexity:
 * O(1)
 *
 * @param stack       - A reference to the stacks of the user.
 *
 * @param data        - Pointer to a buffer in which the top most data will be
 *                      stored.
 *
 * @return            - A pointer to a datastructure on the top of the stack.
 */
void stacks_peek(const struct Stacks *stack, void *data);

/*
 * stacks_capacity()
 * *****************
 * Returns the maximum capacity of the stack.
 *
 * Complexity:
 * O(1)
 *
 * @param stack       - A reference to the stacks of the user.
 *
 * @return            - The capacity of the stack.
 */
unsigned int stacks_capacity(const struct Stacks *stack);

/*
 * stacks_size()
 * *************
 * Returns the number of elements currently on the stack.
 *
 * Complexity:
 * O(1)
 *
 * @param stack       - A reference to the stacks of the user.
 *
 * @return            - The size of the stack.
 */
unsigned int stacks_size(const struct Stacks *stack);

/*
 * stacks_structsize()
 * *******************
 * Returns the size of the elements stored on the stack.
 *
 * Complexity:
 * O(1)
 *
 * @param queue       - A reference to the stacks of the user.
 *
 * @return            - The size of the structs in the queue.
 */
unsigned int stacks_structsize(const struct Stacks *stack);

/*
 * stacks_destroy()
 * ****************
 * Frees the array in which the elements are stored.
 *
 * Complexity:
 * O(1)
 *
 * @param stack       - A reference to the stacks of the user.
 *
 * @return            - void
 */
void stacks_destroy(struct Stacks *stack);

#endif
