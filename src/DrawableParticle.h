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
void DrawableParticle_set_x(DrawableParticle *self, float x);
void DrawableParticle_set_y(DrawableParticle *self, float y);
void DrawableParticle_set_mass(DrawableParticle *self, float mass);

#endif
