#ifndef _TRIANGLE_H_
#define _TRIANGLE_H_

#include "Drawer.h"


typedef struct TriangleTag {
    Drawer *drawer;
    float x;
    float y;
    float ax;
    float ay;
    float bx;
    float by;
    float cx;
    float cy;
} Triangle;


Triangle *Triangle_main(Drawer *drawer);
void Triangle_destroy(Triangle *self);
void Triangle_draw(Triangle *self);

#endif
