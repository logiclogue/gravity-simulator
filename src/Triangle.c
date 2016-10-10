#include <stdlib.h>
#include "Triangle.h"
#include "Drawer.h"


Triangle *Triangle_main(Drawer *drawer)
{
    Triangle *self = malloc(sizeof(Triangle));

    self->drawer = drawer;

    self->x = 0;
    self->y = 0;
    self->ax = 0;
    self->ay = 0;
    self->bx = 0;
    self->by = 0;
    self->cx = 0;
    self->cy = 0;

    return self;
}


void Triangle_destroy(Triangle *self)
{
    free(self);
}

void Triangle_draw(Triangle *self)
{
    float x = self->x;
    float y = self->y;

    Drawer_draw_triangle(self->drawer,
        x + self->ax, y + self->ay,
        x + self->bx, y + self->by,
        x + self->cx, y + self->cy);
}
