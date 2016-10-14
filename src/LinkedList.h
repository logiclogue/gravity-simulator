#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

#include "LinkedListNode.h"


typedef struct LinkedListTag {
    LinkedListNode *root_node;
    LinkedListNode *last_node;
    LinkedListNode *current_node;
} LinkedList;


LinkedList *LinkedList_new(void);
void LinkedList_add(LinkedList *self, LinkedListNode *node);
void LinkedList_remove(LinkedList *self, LinkedListNode *node);
LinkedListNode LinkedList_next(LinkedList *self);
LinkedListNode LinkedList_jump(LinkedList *self, LinkedListNode *node);

#endif
