#include <stdlib.h>
#include <math.h>
#include "Camera.h"


Camera *Camera_new(void)
{
    Camera *self = malloc(sizeof(Camera));

    self->x = 0;
    self->y = 0;
    self->zoom = 0.1;
    
    return self;
}


void Camera_set_zoom(Camera *self, float zoom)
{
    self->zoom = exp2(zoom);
}
