#include <stdlib.h>
#include "Camera.h"


Camera *Camera_main(void)
{
    Camera *self = malloc(sizeof(Camera));

    self->x = 0;
    self->y = 0;
    self->zoom = 0;
    
    return self;
}
