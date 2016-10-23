#include "DrawableUniverse.h"
#include "DrawableParticle.h"
#include "Universe.h"
#include "Circle.h"
#include "Particle.h"


static void test_callback(Universe *self, LinkedListNode *node);
static void test_callback_compare(Universe *self,
    LinkedListNode *node_a, LinkedListNode *node_b);


Universe *DrawableUniverse_new(void)
{
    return Universe_new();
}


void DrawableUniverse_destroy(Universe *self)
{
    Universe_destroy(self);
}

void DrawableUniverse_add(Universe *self, DrawableParticle *particle)
{
    Universe_add(self, (void *)particle);
}

void DrawableUniverse_test(Universe *self)
{
    Universe_loop(self, (void *)test_callback, (void *)test_callback_compare);
}

static void test_callback(Universe *self, LinkedListNode *node)
{
    DrawableParticle *drawable_particle = node->data;
    Circle *circle = drawable_particle->circle;

    Circle_draw(circle);
}

static void test_callback_compare(Universe *self,
    LinkedListNode *node_a, LinkedListNode *node_b)
{
    DrawableParticle *d_particle_a = node_a->data;
    DrawableParticle *d_particle_b = node_b->data;
    Particle *particle_a = d_particle_a->particle;
    Particle *particle_b = d_particle_b->particle;

    Gravity_interact_particles(self->gravity, particle_a, particle_b);
    DrawableParticle_redraw(d_particle_a);
}
