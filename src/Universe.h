#ifndef _UNIVERSE_H_
#define _UNIVERSE_H_

#include "Particle.h"


typedef struct UniverseTag {
    Particle **particles;
    int particle_count;
} Universe;

#endif
