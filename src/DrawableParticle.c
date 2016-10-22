#include "DrawableParticle.h"
#include "Particle.h"
#include "Circle.h"
#include "Coords.h"
#include "Drawer.h"


DrawableParticle *DrawableParticle_new(Drawer *drawer)
{
    DrawableParticle *self = malloc(sizeof(DrawableParticle));

    self->coords = Coords_new();
    self->particle = Particle_new(1);
    self->particle->coords = self->coords;
    self->circle = Circle_new(drawer);
    self->circle->coords = self->coords;

    return self;
}


void DrawableParticle_set_x(DrawableParticle *self, float x)
{
    self->coords->x = x;

    Circle_set_x(self->circle, x);
}

void DrawableParticle_set_y(DrawableParticle *self, float y)
{
    self->coords->y = y;

    Circle_set_y(self->circle, y);
}

void DrawableParticle_set_mass(DrawableParticle *self, float mass)
{
    self->particle->mass = mass;

    Circle_set_radius(self->circle, mass);
}
