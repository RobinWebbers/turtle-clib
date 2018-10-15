#ifndef STACKD_H
#define STACKD_H

/*
 * Stackd
 * ******
 * A dynamic stack. To use this datastructure, instantiate a struct Stackd * and
 * set it to NULL. When a double pointer is required for these functions,
 * reference the stack *. This stack is a singly linked list and generic. Any
 * type of datastructure can be referenced to be copied onto the stack. For
 * larger datastructures, storing a pointer to this datastructure is adviced.
 * Small datastructures can be copied directly to avoid the overhead of the
 * saved pointer.
 */
struct Stackd
{
    struct Stackd *next;
    //Data is malloced thogether with Stackd:
    //malloc(sizeof(struct Stackd) + structsize)
};

/*
 * stackd_push()
 * *************
 * Push a datastructure as the new top of the stack. Data should be a reference
 * to the to be pushed datastructure and structsize the sizeof this structure.
 * For large structures, pushing pointers to those structures is adviced.
 *
 * Complexity:
 * O(1)
 *
 * @param stack       - A reference to the stackd * of the user. Pushing to an
 *                      empty stack requires the reference of a NULL.
 *
 * @param data        - Pointer to a datastructure to be pushed onto the stack.
 *
 * @param structsize  - The size of the datastructure which will be copied to
 *                      the node pushed onto the stack.
 *
 * @return            - void
 */
void stackd_push(struct Stackd **stack, const void *data, unsigned int structsize);

/*
 * stackd_pop()
 * ************
 * Pop a datastructure from the top of the stack. Data should be a reference to
 * a buffer of apropriate size for the popped datastructure.
 *
 * Complexity:
 * O(1)
 *
 * @param stack       - A reference to the stackd * of the user. Checking
 *                      whether the stack is empty is the users responsibility.
 *
 * @param data        - A pointer to a buffer to which the data the top node
 *                      holds can be copied to.
 *
 * @param structsize  - The size of the datastructure which will be copied to
 *                      the buffer passed.
 *
 * @return            - void
 */
void stackd_pop(struct Stackd **stack, void *data, unsigned int structsize);

/*
 * stackd_peek()
 * *************
 * Peek at the datastructure on the top of the stack. Data should be a reference
 * to a buffer of apropriate size for the peeked at datastructure.
 *
 * Complexity:
 * O(1)
 *
 * @param stack       - The stackd * of the user. Checking whether the stack is
 *                      empty is the users responsibility.
 *
 * @param data        - A pointer to a buffer to which the data the top node
 *                      holds can be copied to.
 *
 * @param structsize  - The size of the datastructure which will be copied to
 *                      the buffer passed.
 *
 * @return            - void
 */
void stackd_peek(const struct Stackd *stack, void *data, unsigned int structsize);

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
unsigned int stackd_size(const struct Stackd *stack);

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
 * @param structsize  - The size of the datastructure which will be copied to
 *                      the node inserted into the stack.
 *
 * @param index       - The index of the new element when it is inserted.
 *
 * @return            - void
 */
void stackd_insert(struct Stackd **stack, const void *data, unsigned int structsize, unsigned int index);

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
 * @param data        - A pointer to a buffer to which the data the removed node
 *                      held can be copied to.
 *
 * @param structsize  - The size of the datastructure which will be copied to
 *                      the buffer passed.
 *
 * @param index       - The index of the element to be removed.
 *
 * @return            - A pointer to the datastructure the node which was
 *                      removed held.
 */
void stackd_remove(struct Stackd **stack, void *data, unsigned int structsize, unsigned int index);

/*
 * stackd_pushLast()
 * *****************
 * Push a datastructure as the new bottom of the stack.
 *
 * Complexity:
 * O(n)
 *
 * @param stack       - A reference to the stackd * of the user. Pushing to an
 *                      empty stack requires the reference of a NULL.
 *
 * @param data        - Pointer to a datastructure to be inserted into the
 *                      stack.
 *
 * @param structsize  - The size of the datastructure which will be copied to
 *                      the node inserted into the stack.
 *
 * @return            - A pointer to the datastructure the node which was
 *                      removed held.
 */
void stackd_pushLast(struct Stackd **stack, const void *data, unsigned int structsize);

/*
 * stackd_popLast()
 * ****************
 * Pop a pointer to a datastructure from the bottom of the stack.
 *
 * Complexity:
 * O(n)
 *
 * @param stack       - A reference to the stackd * of the user. Checking
 *                      whether the stack is empty is the users responsibility.
 *
 * @param data        - A pointer to a buffer to which the data the last node
 *                      holds can be copied to.
 *
 * @param structsize  - The size of the datastructure which will be copied to
 *                      the buffer passed.
 *
 * @return            - A pointer to the datastructure previously pushed onto
 *                      the stack.
 */
void stackd_popLast(struct Stackd **stack, void *data, unsigned int structsize);

/*
 * stackd_peekLast()
 * *****************
 * Peek at a pointer to a datastructure from the bottom of the stack.
 *
 * Complexity:
 * O(n)
 *
 * @param stack       - The stackd * of the user. Checking whether the stack is
 *                      empty is the users responsibility.
 *
 * @param data        - A pointer to a buffer to which the data the last node
 *                      holds can be copied to.
 *
 * @param structsize  - The size of the datastructure which will be copied to
 *                      the buffer passed.
 *
 * @return            - A pointer to the datastructure the bottom node holds.
 */
void stackd_peekLast(const struct Stackd *stack, void *data, unsigned int structsize);

#endif
