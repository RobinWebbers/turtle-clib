#ifndef STACKS_H
#define STACKS_H

/*
 * Stacks
 * ******
 * A static stack. To use this datastructure, allocate the Stacks struct and
 * init the stack. This sets the capacity of the stack. When done with the
 * stack, do not forget to destroy it. This stack is generic, since it holds an
 * array of void *s.
 */
struct Stacks
{
    unsigned int capacity, size;
    void **data;
};

/*
 * stacks_init()
 * *************
 * Initiate the stack with the desired capacity. This function must be called
 * for the static stack to work correctly.
 *
 * Complexity:
 * O(1)
 *
 * @param stack       - A reference to the stacks of the user.
 *
 * @param capacity    - The maximum number of elements on the stack.
 *
 * @return            - void
 */
void stacks_init(struct Stacks *stack, unsigned int capacity);

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
void stacks_push(struct Stacks *stack, void *data);

/*
 * stacks_pop()
 * ************
 * Pop a pointer to a datastructure from the top of the stack.
 *
 * Complexity:
 * O(1)
 *
 * @param stack       - A reference to the stacks of the user.
 *
 * @return            - A pointer to a datastructure on the top of the stack.
 */
void *stacks_pop(struct Stacks *stack);

/*
 * stacks_peek()
 * *************
 * Peek at a pointer to a datastructure from the top of the stack.
 *
 * Complexity:
 * O(1)
 *
 * @param stack       - A reference to the stacks of the user.
 *
 * @return            - A pointer to a datastructure on the top of the stack.
 */
void *stacks_peek(struct Stacks *stack);

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
unsigned int stacks_capacity(struct Stacks *stack);

/*
 * stacks_size()
 * *****************
 * Returns the number of elements currently on the stack.
 *
 * Complexity:
 * O(1)
 *
 * @param stack       - A reference to the stacks of the user.
 *
 * @return            - The size of the stack.
 */
unsigned int stacks_size(struct Stacks *stack);

/*
 * stacks_capacity()
 * *****************
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
