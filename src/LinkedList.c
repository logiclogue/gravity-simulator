#include <stdlib.h>
#include "LinkedList.h"
#include "LinkedListNode.h"


LinkedList *LinkedList_new(void)
{
    LinkedList *self = malloc(sizeof(LinkedList));

    self->root_node = NULL;
    self->current_node = NULL;
    self->last_node = NULL;

    return self;
}


void LinkedList_destroy(LinkedList *self)
{
    while (self->current_node != NULL) {
        LinkedListNode_destroy(self->current_node);
        LinkedList_next(self);
    }
}

void LinkedList_add(LinkedList *self, LinkedListNode *node)
{
    node->previous_node = self->last_node;

    if (self->last_node != NULL) {
        self->last_node->next_node = node;
    }

    self->last_node = node;
}

void LinkedList_remove(LinkedList *self, LinkedListNode *node)
{
    if (node->next_node != NULL) {
        node->next_node->previous_node = node->previous_node;
    }

    if (node->previous_node != NULL) {
        node->previous_node->next_node = node->next_node;
    }

    LinkedListNode_destroy(node);
}

LinkedListNode *LinkedList_next(LinkedList *self)
{
    self->current_node = LinkedList_next_node(self, self->current_node);
    
    return self->current_node;
}

LinkedListNode *LinkedList_next_node(LinkedList *self, LinkedListNode *node)
{
    LinkedListNode *next_node = node;

    if (node->next_node == NULL) {
        next_node = self->root_node;
    } else {
        next_node = node->next_node;
    }

    return next_node;
}
