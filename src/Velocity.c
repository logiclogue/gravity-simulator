#include <stdlib.h>
#include "Velocity.h"


Velocity *Velocity_new(void)
{
    Velocity *self = malloc(sizeof(Velocity));

    self->x = 0;
    self->y = 0;

    return self;
}


void Velocity_append(float *velocity_component, float change_velocity)
{
    *velocity_component += change_velocity;
}
