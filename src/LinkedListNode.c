#include <stdlib.h>
#include "LinkedListNode.h"


typedef LinkedListNode Node;


LinkedListNode *LinkedListNode_new(void *data)
{
    Node *node = malloc(sizeof(Node));

    node->data = data;
    node->next_node = NULL;
    node->previous_node = NULL;

    return node;
}


void LinkedListNode_destroy(LinkedListNode *self)
{
    free(self);
}
