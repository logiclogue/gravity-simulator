#ifndef _DRAWABLE_UNIVERSE_H_
#define _DRAWABLE_UNIVERSE_H_

#include "DrawableParticle.h"
#include "Universe.h"
#include "LinkedList.h"


Universe *DrawableUniverse_new(void);
void DrawableUniverse_destroy(Universe *self);
void DrawableUniverse_add(Universe *self, DrawableParticle *particle);
void DrawableUniverse_test(Universe *self);

#endif
