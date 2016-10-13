#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

#include "LinkedListNode.h"


typedef struct LinkedListTag {
    LinkedListNode *first_node;
    LinkedListNode *last_node;
} LinkedList;

#endif
