#include <stdlib.h>
#include "Gravity.h"


Gravity *Gravity_new(void)
{
    Gravity *self = malloc(sizeof(Gravity));

    self->constant = 1;

    return self;
}


float Gravity_force(Gravity *self,
    Particle *particle_a, Particle *particle_b, float distance)
{
    float mass_a = particle_a->mass;
    float mass_b = particle_b->mass;
    float distance_square = distance * distance;

    if (distance_square == 0) {
        return 0;
    }

    return (self->constant * mass_a * mass_b) / distance_square;
}

float Gravity_force_x(Gravity *self,
    Particle *particle_a, Particle *particle_b)
{
    float a_x = particle_a->coords->x;
    float b_x = particle_b->coords->x;
    float distance_x = b_x - a_x;

    return Gravity_force(self, particle_a, particle_b, distance_x);
}

float Gravity_force_y(Gravity *self,
    Particle *particle_a, Particle *particle_b)
{
    float a_y = particle_a->coords->y;
    float b_y = particle_b->coords->y;
    float distance_y = b_y - a_y;

    return Gravity_force(self, particle_a, particle_b, distance_y);
}