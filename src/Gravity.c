#include <stdlib.h>
#include "Gravity.h"


Gravity *Gravity_new(void)
{
    Gravity *self = malloc(sizeof(Gravity));

    self->constant = 1;

    return self;
}


float Gravity_force(Gravity *self, Particle *particle_a, Particle *particle_b, float distance)
{
    float mass_a = particle_a->mass;
    float mass_b = particle_b->mass;
    float distance_square = distance * distance;

    return (self->constant * mass_a * mass_b) / distance_square;
}
