#include <stdlib.h>
#include "Universe.h"
#include "Particle.h"
#include "LinkedList.h"
#include "LinkedListNode.h"


Universe *Universe_new(void)
{
    Universe *self = malloc(sizeof(Universe));

    self->particles = LinkedList_new();

    return self;
}


void Universe_destroy(Universe *self)
{
    LinkedList_destroy(self->particles);
    free(self);
}

void Universe_add(Universe *self, Particle *particle)
{
    LinkedListNode *node = LinkedListNode_new(particle);

    LinkedList_add(self->particles, node);
}

void Universe_test(Universe *self)
{
    LinkedListNode *node_a = self->particles->root_node;
    LinkedListNode *node_b = self->particles->root_node;

    while (node_a != NULL) {
        while (node_b != NULL) {
            // TODO: Compare both particles here and operate gravity.
            //node_a->data;
            //node_b->data;

            node_b = LinkedList_next_node(self->particles, node_b);
        }

        node_a = LinkedList_next_node(self->particles, node_a);
    }
}
