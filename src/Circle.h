#ifndef _CIRCLE_H_
#define _CIRCLE_H_

#include "Triangle.h"
#include "Drawer.h"


typedef struct CircleTag {
    Triangle **triangles;
    Drawer *drawer;
    float x;
    float y;
    float radius;
    int triangle_count;
} Circle;


Circle *Circle_main(Drawer *drawer);
void Circle_draw(Circle *self);

#endif
