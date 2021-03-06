#include <math.h>
#include <stdlib.h>
#include "Gravity.h"


Gravity *Gravity_new(void)
{
    Gravity *self = malloc(sizeof(Gravity));

    self->constant = 0.001;

    return self;
}


float Gravity_force(Gravity *self,
    Particle *particle_a, Particle *particle_b, float distance)
{
    float mass_a = particle_a->mass;
    float mass_b = particle_b->mass;
    float distance_square = distance * distance;
    float force;

    if (distance_square == 0) {
        return 0;
    }
    
    force = (self->constant * mass_a * mass_b) / distance_square;

    return force;
}

float *Gravity_force_directly(Gravity *self,
    Particle *particle_a, Particle *particle_b)
{
    float diff_x = particle_b->coords->x - particle_a->coords->x;
    float diff_y = particle_b->coords->y - particle_a->coords->y;
    float distance = sqrt((diff_x * diff_x) + (diff_y * diff_y));
    float force = Gravity_force(self, particle_a, particle_b, distance);
    float force_x = (diff_x * force) / distance;
    float force_y = (diff_y * force) / distance;
    static float forces[2];

    forces[0] = force_x;
    forces[1] = force_y;

    return forces;
}

void Gravity_interact_particles(Gravity *self,
    Particle *particle_a, Particle *particle_b)
{
    float mass = particle_a->mass;
    float *forces = Gravity_force_directly(self, particle_a, particle_b);
    float force_x = forces[0];
    float force_y = forces[1];
    float delta_velocity_x = force_x / mass;
    float delta_velocity_y = force_y / mass;

    Velocity_append(&particle_a->velocity->x, delta_velocity_x);
    Velocity_append(&particle_a->velocity->y, delta_velocity_y);
}
