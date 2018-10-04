#ifndef STACKD_H
#define STACKD_H

struct Stackd
{
    struct Stackd *next;
    void *data;
};

/*
 * stackd_push()
 * *************
 * Push a pointer to a datastructure on top of the stack.
 *
 * Complexity:
 * O(1)
 *
 * @param stack       - A reference to the stackd * of the user. Pushing to an
 *                      empty stack requires the reference of a NULL.
 *
 * @param data        - Pointer to a datastructure to be pushed onto the stack.
 *
 * @return            - void
 */
void stackd_push(struct Stackd **stack, void *data);

/*
 * stackd_pop()
 * ************
 * Pop a pointer to a datastructure from the top of the stack.
 *
 * Complexity:
 * O(1)
 *
 * @param stack       - A reference to the stackd * of the user. Checking
 *                      whether the stack is empty is the users responsibility.
 *
 * @return            - A pointer to the datastructure previously pushed onto
 *                      the stack.
 */
void *stackd_pop(struct Stackd **stack);

/*
 * stackd_peek()
 * *************
 * Peek at a pointer to a datastructure from the top of the stack.
 *
 * Complexity:
 * O(1)
 *
 * @param stack       - The stackd * of the user. Checking whether the stack is
 *                      empty is the users responsibility.
 *
 * @return            - A pointer to the datastructure the bottom node holds.
 */
void *stackd_peek(struct Stackd *stack);

/*
 * stackd_size()
 * *************
 * Returns the current number of elements on the stack.
 *
 * Complexity:
 * O(n)
 *
 * @param stack       - The stackd * of the user. Checking whether the stack is
 *                      empty is the users responsibility.
 *
 * @return            - Number of elements on the stack.
 */
int stackd_size(struct Stackd *stack);

/*
 * stackd_reverse()
 * ****************
 * Reverse the order of the stack.
 *
 * Complexity:
 * O(n)
 *
 * @param stack       - A reference to the stackd * of the user.
 *
 * @return            - void
 */
void stackd_reverse(struct Stackd **stack);

/*
 * stackd_insert()
 * ***************
 * Insert a new element onto the stack at the given index. This function has no
 * bounds checking.
 *
 * Complexity:
 * O(index)
 *
 * @param stack       - A reference to the stackd * of the user.
 *
 * @param data        - Pointer to a datastructure to be inserted into the
 *                      stack.
 *
 * @param index       - The index of the new element when it is inserted.
 *
 * @return            - void
 */
void stackd_insert(struct Stackd **stack, void *data, int index);

/*
 * stackd_remove()
 * ***************
 * Remove an element from the stack at the given index. This function has no
 * bounds checking.
 *
 * Complexity:
 * O(index)
 *
 * @param stack       - A reference to the stackd * of the user.
 *
 * @param index       - The index of the element to be removed.
 *
 * @return            - A pointer to the datastructure the node which was
 *                      removed held.
 */
void *stackd_remove(struct Stackd **stack, int index);

/*
 * stackd_pushl()
 * **************
 * Push a pointer to a datastructure as the new bottom of the stack.
 *
 * Complexity:
 * O(n)
 *
 * @param stack       - A reference to the stackd * of the user. Pushing to an
 *                      empty stack requires the reference of a NULL.
 *
 * @param data        - Pointer to a datastructure to be pushed onto the stack.
 *
 * @return            - A pointer to the datastructure the node which was
 *                      removed held.
 */
void stackd_pushl(struct Stackd **stack, void *data);

/*
 * stackd_popl()
 * *************
 * Pop a pointer to a datastructure from the bottom of the stack.
 *
 * Complexity:
 * O(n)
 *
 * @param stack       - A reference to the stackd * of the user. Checking
 *                      whether the stack is empty is the users responsibility.
 *
 * @return            - A pointer to the datastructure previously pushed onto
 *                      the stack.
 */
void *stackd_popl(struct Stackd **stack);

/*
 * stackd_peekl()
 * **************
 * Peek at a pointer to a datastructure from the bottom of the stack.
 *
 * Complexity:
 * O(n)
 *
 * @param stack       - The stackd * of the user. Checking whether the stack is
 *                      empty is the users responsibility.
 *
 * @return            - A pointer to the datastructure the bottom node holds.
 */
void *stackd_peekl(struct Stackd *stack);

#endif
