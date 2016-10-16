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
    while (self->particles->current_node != NULL) {
        LinkedList_next(self->particles);

        // another loop here!
    }
}
