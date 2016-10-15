#ifndef _UNIVERSE_H_
#define _UNIVERSE_H_

#include "Particle.h"
#include "LinkedList.h"


typedef struct UniverseTag {
    LinkedList *particles;
} Universe;


Universe *Universe_new(void);
void Universe_destroy(Universe *self);

#endif
