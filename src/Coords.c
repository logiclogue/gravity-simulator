#include <stdlib.h>
#include "Coords.h"


Coords *Coords_new()
{
    Coords *self = malloc(sizeof(Coords));

    self->x = 0;
    self->y = 0;

    return self;
}


void Coords_destroy(Coords *self)
{
    free(self);
}
