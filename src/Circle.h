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
void Circle_destroy(Circle *self);
void Circle_draw(Circle *self);
void Circle_set_x(Circle *self, float x);
void Circle_set_y(Circle *self, float y);
void Circle_set_radius(Circle *self, float radius);
void Circle_update_triangles(Circle *self);

#endif
