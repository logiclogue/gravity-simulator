#include "DrawableParticle.h"
#include "Particle.h"
#include "Circle.h"
#include "Coords.h"
#include "Drawer.h"


DrawableParticle *DrawableParticle_new(Drawer *drawer)
{
    DrawableParticle *self = malloc(sizeof(DrawableParticle));

    self->coords = Coords_new();
    self->particle = Particle_new(0);
    self->circle = Circle_new(drawer);

    return self;
}
