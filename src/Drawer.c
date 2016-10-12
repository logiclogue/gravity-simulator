#include <GL/glu.h>
#include <stdlib.h>
#include "Camera.h"
#include "Drawer.h"
#include "Frame.h"


Drawer *Drawer_new(Camera *camera, Frame *frame)
{
    Drawer *self = malloc(sizeof(Drawer));

    self->camera = camera;
    self->frame = frame;

    return self;
}


void Drawer_draw_triangle(Drawer *self,
    float ax, float ay,
    float bx, float by,
    float cx, float cy)
{
    float xu = self->frame->width_unit;
    float yu = self->frame->height_unit;
    float xo = self->camera->x;
    float yo = self->camera->y;

    glBegin(GL_TRIANGLES);
        glVertex2f((xo + ax) * xu, (yo + ay) * yu);
        glVertex2f((xo + bx) * xu, (yo + by) * yu);
        glVertex2f((xo + cx) * xu, (yo + cy) * yu);
    glEnd();
}

void Drawer_clear(Drawer *self)
{
    glClear(GL_COLOR_BUFFER_BIT);
}
