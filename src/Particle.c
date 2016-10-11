#include <stdlib.h>
#include "Particle.h"


Particle *Particle_main(float mass)
{
    Particle *self = malloc(sizeof(Particle));

    self->x = 0;
    self->y = 0;
    self->mass = mass;
    self->radius = 0;

    return self;
}


void Particle_destroy(Particle *self)
{
    free(self);
}
