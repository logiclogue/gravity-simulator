#include <stdlib.h>
#include "Particle.h"


Particle *Particle_new(float mass)
{
    Particle *self = malloc(sizeof(Particle));

    self->coords = Coords_new();
    self->mass = mass;
    self->velocity_x = 0;
    self->velocity_y = 0;

    return self;
}


void Particle_destroy(Particle *self)
{
    free(self);
}
