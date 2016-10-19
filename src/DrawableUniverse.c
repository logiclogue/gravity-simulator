#include "DrawableUniverse.h"
#include "Universe.h"
#include "Circle.h"
#include "Particle.h"


static void draw_callback(Universe *self, LinkedListNode *node);


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
    Universe_loop(self, (void *)draw_callback, NULL);
}

static void draw_callback(Universe *self, LinkedListNode *node)
{
    Circle *circle = node->data->circle;
    Particle *particle = node->data->particle;

    Circle_draw(circle);
}
