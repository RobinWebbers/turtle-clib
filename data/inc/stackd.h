#ifndef STACKD_H
#define STACKD_H

#include <stdbool.h>

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
 * Peek at the datastructure on the top of the stack. This pointer can be made
 * invalid upon removing the node which carries this data. Please copy it if
 * persistent usage is needed.
 *
 * Complexity:
 * O(1)
 *
 * @param stack       - The stackd * of the user. Checking whether the stack is
 *                      empty is the users responsibility.
 *
 * @return            - Returns a pointer to the datastructure the top node
 *                      holds.
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
 * @return            - void
 */
void stackd_remove(struct Stackd **stack, void *data, unsigned int structsize, unsigned int index);

/*
 * stackd_contains()
 * *****************
 * Check whether the stack contains data which corresponds to the given key. The
 * first occurrence of the key is returned. A NULL is returned upon unsuccesful
 * search. The compare function evaluates the key as the first argument and the
 * data as the second argument. Upon a succesful compare, the function should
 * return 0. This pointer can be made invalid upon removing the node which
 * carries this data. Please copy it if persistent usage is needed.
 *
 *
 * Complexity:
 * O(n)
 *
 * @param stack       - The stackd * of the user. Checking whether the stack is
 *                      empty is the users responsibility.
 *
 * @param key         - A key for which the stack is searched to find the first
 *                      node whose data corresponds to it.
 *
 * @param compare     - A pointer to a compare function. It takes as first
 *                      argument the key and as second argument the data. It
 *                      returns 0 upon finding equality.
 *
 * @return            - Returns a pointer to the datastructure of a node whose
 *                      data corresponds to the given key.
 */
void *stackd_contains(struct Stackd *stack, const void *key, int (*compare)(const void *, const void *));

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
 * @return            - void
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
 * @return            - void
 */
void stackd_popLast(struct Stackd **stack, void *data, unsigned int structsize);

/*
 * stackd_peekLast()
 * *****************
 * Peek at the datastructure on the bottom of the stack. This pointer can be
 * made invalid upon removing the node which carries this data. Please copy it
 * if persistent usage is needed.
 *
 *
 * Complexity:
 * O(n)
 *
 * @param stack       - The stackd * of the user. Checking whether the stack is
 *                      empty is the users responsibility.
 *
 * @return            - A pointer to the datastructure the bottom node holds.
 */
void *stackd_peekLast(struct Stackd *stack);

#endif
