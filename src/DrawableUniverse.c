#include "Universe.h"


DrawableUniverse *DrawableUniverse_new(void)
{
    return Universe_new();
}


void DrawableUniverse_destroy(DrawableUniverse *self)
{
    Universe_destroy(self);
}

void DrawableUniverse_add(DrawableUniverse *self, DrawableParticle *particle)
{
    Universe_add(self, (void *)particle);
}

void DrawableUniverse_test(DrawableUniverse *self)
{
}
