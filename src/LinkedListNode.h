#ifndef _LINKED_LIST_NODE_H_
#define _LINKED_LIST_NODE_H_

typedef struct LinkedListNodeTag {
    void *data;
    struct LinkedListNodeTag *next_node;
    struct LinkedListNodeTag *previous_node;
} LinkedListNode;


LinkedListNode *LinkedListNode_new(void *data);

#endif
