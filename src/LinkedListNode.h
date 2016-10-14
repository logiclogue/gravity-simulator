#ifndef _LINKED_LIST_NODE_H_
#define _LINKED_LIST_NODE_H_

typedef struct LinkedListNodeTag {
    void *data;
    LinkedListNode *next_node;
    LinkedListNode *previous_node;
} LinkedListNode;


LinkedListNode *LinkedListNode_new(void);

#endif
