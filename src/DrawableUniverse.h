#ifndef _DRAWABLE_UNIVERSE_H_
#define _DRAWABLE_UNIVERSE_H_

#include "DrawableParticle.h"
#include "Universe.h"
#include "LinkedList.h"


typedef Universe DrawableUniverse;


DrawableUniverse *DrawableUniverse_new(void);
void DrawableUniverse_destroy(DrawableUniverse *self);
void DrawableUniverse_add(DrawableUniverse *self, DrawableParticle *particle);
void DrawableUniverse_test(DrawableUniverse *self);
