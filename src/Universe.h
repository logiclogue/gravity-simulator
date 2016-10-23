#ifndef _UNIVERSE_H_
#define _UNIVERSE_H_

#include "Particle.h"
#include "LinkedList.h"
#include "Gravity.h"


typedef struct UniverseTag {
    LinkedList *particles;
    Gravity *gravity;
} Universe;


Universe *Universe_new(void);
void Universe_destroy(Universe *self);
void Universe_add(Universe *self, Particle *particle);
void Universe_test(Universe *self);
void Universe_loop(Universe *self,
    void (*callback)(void *, LinkedListNode *),
    void (*callback_compare)(void *, LinkedListNode *, LinkedListNode *));

#endif
