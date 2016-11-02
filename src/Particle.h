#ifndef _PARTICLE_H_
#define _PARTICLE_H_

#include "Coords.h"
#include "Velocity.h"


typedef struct ParticleTag {
    Coords *coords;
    Velocity *velocity;
    float mass;
    float radius;
    float velocity_x;
    float velocity_y;
} Particle;


Particle *Particle_new(float mass);
void Particle_destroy(Particle *self);

#endif
