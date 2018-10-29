#ifndef NODE_H
#define NODE_H

/*
 * Node
 * ****
 * A node for a doubly linked list. This datastructure can be used as is, or a
 * wrapper can be built around this. To use, set the starting node to NULL, this
 * signifies an empty list. Most functions for this node require a reference to
 * the node used in the main program. This doubly linked list is generic. Any
 * type of datastructure can be referenced to be copied into the list. For
 * larger datastructures, storing a pointer to this datastructure is adviced.
 * Small datastructures can be copied directly to avoid the overhead of the
 * saved pointer.
 *
 */
struct Node
{
    struct Node *prev, *next;
    //Data is malloced thogether with Node:
    //malloc(sizeof(struct Node) + structsize)
};

/*
 * node_insertAfter()
 * ******************
 * Insert an element after the current node. The passed node points to the newly
 * added node. Data should be a reference to the to be pushed datastructure and
 * structsize the sizeof this structure. For large structures, inserting
 * pointers to those structures is adviced.
 *
 * Complexity:
 * O(1)
 *
 * @param node        - A reference to a node pointer.
 *
 * @param data        - A pointer to the datastructure to be inserted with the
 *                      new node.
 *
 * @param structsize  - The size of the datastructure which will be copied to
 *                      the new node.
 *
 * @return            - void
 */
void node_insertAfter(struct Node **node, const void *data, unsigned int structsize);

/*
 * node_insertBefore()
 * *******************
 * Insert an element before the current node. The passed node points to the
 * newly added node. Data should be a reference to the to be pushed
 * datastructure and structsize the sizeof this structure. For large structures,
 * inserting pointers to those structures is adviced.
 *
 * Complexity:
 * O(1)
 *
 * @param node        - A reference to a node pointer.
 *
 * @param data        - A pointer to the datastructure to be inserted with the
 *                      new node.
 *
 * @param structsize  - The size of the datastructure which will be copied to
 *                      the new node.
 *
 * @return            - void
 */
void node_insertBefore(struct Node **node, const void *data, unsigned int structsize);

/*
 * node_peek()
 * ***********
 * Peek at the datastructure in the current node. Data should be a reference to
 * a buffer of apropriate size for the peeked at datastructure.
 *
 * Complexity:
 * O(1)
 *
 * @param node        - A node pointer.
 *
 * @param data        - A pointer to the datastructure to be inserted with the
 *                      new node.
 *
 * @param structsize  - The size of the datastructure which will be copied to
 *                      the new node.
 *
 * @return            - void
 */
void node_peek(struct Node *node, void *data, unsigned int structsize);

/*
 * node_remove()
 * *************
 * Remove the current node from the linked list. The node passed points to the
 * next node if this is not NULL. Otherwhise, it points to the previous node in
 * the list.
 *
 * Complexity:
 * O(1)
 *
 * @param node        - A reference to a node pointer.
 *
 * @return            - void
 */
void node_remove(struct Node **node);

/*
 * node_first()
 * ************
 * Move the node pointer to the first node in the linked list. No checks for an
 * empty list.
 *
 * Complexity:
 * O(n)
 *
 * @param node        - A reference to a node pointer.
 *
 * @return            - void
 */
void node_first(struct Node **node);

/*
 * node_last()
 * ************
 * Move the node pointer to the last node in the linked list. No checks for an
 * empty list.
 *
 * Complexity:
 * O(n)
 *
 * @param node        - A reference to a node pointer.
 *
 * @return            - void
 */
void node_last(struct Node **node);

#endif
