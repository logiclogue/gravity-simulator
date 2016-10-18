#include "DrawableUniverse.h"
#include "Universe.h"


static void test_callback(Universe *self,
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
    Universe_loop(self, (void *)test_callback);
}

static void test_callback(Universe *self,
    LinkedListNode *node_a, LinkedListNode *node_b)
{
    
}
