#ifndef _PARTICLE_H_
#define _PARTICLE_H_


typedef struct ParticleTag {
    float x;
    float y;
    float mass;
    float radius;
} Particle;


Particle *Particle_main(float mass);
void Particle_destroy(Particle *self);

#endif
