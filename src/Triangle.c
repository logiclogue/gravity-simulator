#include <stdlib.h>
#include "Triangle.h"


Triangle *Triangle_main(void)
{
    Triangle *self = malloc(sizeof(Triangle));

    self->ax = 0;
    self->ay = 0;
    self->bx = 0;
    self->by = 0;
    self->cx = 0;
    self->cy = 0;

    return self;
}


void Triangle_draw(Triangle *self)
{
    
}
