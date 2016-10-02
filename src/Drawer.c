#include <GL/glu.h>
#include <stdlib.h>
#include "Drawer.h"


Drawer *Drawer_main(Camera *camera, Frame *frame)
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

    glBegin(GL_TRIANGLES);
        glVertex2f(ax * xu, ay * yu);
        glVertex2f(bx * xu, by * yu);
        glVertex2f(cx * xu, cy * yu);
    glEnd();
}
