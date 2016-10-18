#include <stdlib.h>
#include "Universe.h"
#include "Particle.h"
#include "LinkedList.h"
#include "LinkedListNode.h"


static void test_callback(Universe *self,
    LinkedListNode *node_a, LinkedListNode *node_b);


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
    Universe_loop(self, (void *)test_callback, NULL);
}

static void test_callback(Universe *self,
    LinkedListNode *node_a, LinkedListNode *node_b)
{
    
}

void Universe_loop(Universe *self,
    void (*callback)(void *, LinkedListNode *, LinkedListNode *),
    void (*callback_2)(void *, LinkedListNode *))
{
    LinkedListNode *node_a = self->particles->root_node;
    LinkedListNode *node_b = self->particles->root_node;

    while (node_a != NULL) {
        while (node_b != NULL) {
            if (node_a == node_b) {
                continue;
            }

            callback((void *)self, node_a, node_b);
            callback_2((void *)self, node_a); // !!!!

            node_b = LinkedList_next_node(self->particles, node_b);
        }

        node_a = LinkedList_next_node(self->particles, node_a);
    }
}
