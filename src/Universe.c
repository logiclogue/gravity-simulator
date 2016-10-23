#include <stdlib.h>
#include "Universe.h"
#include "Particle.h"
#include "LinkedList.h"
#include "LinkedListNode.h"
#include "Gravity.h"


static void test_callback(Universe *self,
    LinkedListNode *node_a, LinkedListNode *node_b);


Universe *Universe_new(void)
{
    Universe *self = malloc(sizeof(Universe));

    self->particles = LinkedList_new();
    self->gravity = Gravity_new();

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
    Universe_loop(self, NULL, (void *)test_callback);
}

static void test_callback(Universe *self,
    LinkedListNode *node_a, LinkedListNode *node_b)
{
    Particle *particle_a = node_a->data;
    Particle *particle_b = node_b->data;

    Gravity_interact_particles(self->gravity, particle_a, particle_b);
}

void Universe_loop(Universe *self,
    void (*callback)(void *, LinkedListNode *),
    void (*callback_compare)(void *, LinkedListNode *, LinkedListNode *))
{
    LinkedListNode *node_a = self->particles->root_node;
    LinkedListNode *node_b = self->particles->root_node;

    while (node_a != NULL) {
        if (callback != NULL) {
            callback((void *)self, node_a);
        }

        while (node_b != NULL) {
            if (node_a == node_b) {
                node_b = node_b->next_node;

                continue;
            }

            if (callback_compare != NULL) {
                callback_compare((void *)self, node_a, node_b);
            }

            node_b = node_b->next_node;
        }

        node_a = node_a->next_node;
    }
}
