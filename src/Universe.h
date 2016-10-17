#ifndef _UNIVERSE_H_
#define _UNIVERSE_H_

#include "Particle.h"
#include "LinkedList.h"


typedef struct UniverseTag {
    LinkedList *particles;
} Universe;


Universe *Universe_new(void);
void Universe_add(Universe *self, Particle *particle);
void Universe_destroy(Universe *self);
void Universe_test(Universe *self);

#endif
