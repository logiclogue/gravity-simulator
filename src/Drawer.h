#ifndef _DRAWER_H_
#define _DRAWER_H_

#include "Camera.h"
#include "Frame.h"


typedef struct DrawerTag {
    Camera *camera;
    Frame *frame;
} Drawer;


Drawer *Drawer_main(Camera *camera, Frame *frame);
void Drawer_draw_triangle(Drawer *self,
    float ax, float ay,
    float bx, float by,
    float cx, float cy);
void Drawer_clear(Drawer *self);

#endif

//typedef struct DrawerTag Drawer;
