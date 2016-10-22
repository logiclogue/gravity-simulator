#ifndef _GRAVITY_H_
#define _GRAVITY_H_

#include "Particle.h"


typedef struct GravityTag {
    float constant;
} Gravity;


Gravity *Gravity_new(void);
float Gravity_force(Gravity *self, Particle *particle_a, Particle *particle_b, float distance);

#endif
