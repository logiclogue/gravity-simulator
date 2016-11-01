#include <stdlib.h>
#include <math.h>
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

void Velocity_get_resultant(Velocity *self)
{
    float x_sqr = self->x * self->x;
    float y_sqr = self->y * self->y;

    return sqrt(x_sqr + y_sqr);
}
