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

    float x[3] = {
        (xo + ax) * xu,
        (xo + bx) * xu,
        (xo + cx) * xu
    };
    float y[3] = {
        (yo + ay) * yu,
        (yo + by) * yu,
        (yo + cy) * yu
    };

    int i;

    for (i = 0; i < 3; i++)
    {
        x[i] *= self->camera->zoom;
        y[i] *= self->camera->zoom;
    }

    glBegin(GL_TRIANGLES);
        glVertex2f(x[0], y[0]);
        glVertex2f(x[1], y[1]);
        glVertex2f(x[2], y[2]);
    glEnd();
}

void Drawer_clear(Drawer *self)
{
    glClear(GL_COLOR_BUFFER_BIT);
}
