#include <stdlib.h>
#include "LinkedList.h"
#include "LinkedListNode.h"


LinkedList *LinkedList_new(void)
{
    LinkedList *self = malloc(sizeof(LinkedList));

    self->root_node = LinkedListNode_new(NULL);

    return self;
}


void *LinkedList_add(LinkedList *self, LinkedListNode *node)
{

}
