#ifndef _DRAWABLE_PARTICLE_H_
#define _DRAWABLE_PARTICLE_H_

#include "Particle.h"
#include "Circle.h"
#include "Coords.h"


typedef struct DrawableParticleTag {
    Coords *coords;
    Particle *particle;
    Circle *circle;
} DrawableParticle;


DrawableParticle *DrawableParticle_new(Drawer *drawer);

#endif
