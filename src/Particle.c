#include <stdlib.h>
#include "Particle.h"
#include "Velocity.h"


Particle *Particle_new(float mass)
{
    Particle *self = malloc(sizeof(Particle));

    self->coords = Coords_new();
    self->velocity = Velocity_new();
    self->mass = mass;

    return self;
}


void Particle_destroy(Particle *self)
{
    free(self);
}
