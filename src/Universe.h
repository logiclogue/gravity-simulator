#ifndef _UNIVERSE_H_
#define _UNIVERSE_H_

#include "Particle.h"
#include "LinkedList.h"


typedef struct UniverseTag {
    LinkedList *particles;
} Universe;


Universe *Universe_new(void);
void Universe_destroy(Universe *self);
void Universe_add(Universe *self, Particle *particle);
void Universe_test(Universe *self);
void Universe_loop(Universe *self,
    void (*callback)(void *, LinkedListNode *),
    void (*compare_callback)(void *, LinkedListNode *, LinkedListNode *));

#endif
