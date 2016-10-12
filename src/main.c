#include <GL/glu.h>
#include "Drawer.h"
#include "Frame.h"
#include "Camera.h"
#include "Triangle.h"
#include "Circle.h"


static void create_triangles(Triangle *top, Triangle *bottom);


int main(void)
{
    Camera *camera = Camera_new();
    Frame *frame = Frame_new(camera);
    Drawer *drawer = Drawer_new(camera, frame);
    Triangle *triangle_top = Triangle_new(drawer);
    Triangle *triangle_bottom = Triangle_new(drawer);
    Circle *circle = Circle_new(drawer);

    float x = 0;

    create_triangles(triangle_top, triangle_bottom);

    while (!frame->is_exit) {
        camera->y = 0.2 * x;

        triangle_top->x = triangle_bottom->x = x;
        Triangle_draw(triangle_top);
        Triangle_draw(triangle_bottom);
        Circle_draw(circle);

        Frame_draw(frame);
        Drawer_clear(drawer);
        Frame_event_loop(frame);

        Circle_set_x(circle, 0.9 * -x);

        x += 0.01;
    }

    return 0;
}


static void create_triangles(Triangle *top, Triangle *bottom)
{
    top->ax = 0.f;
    top->ay = 1.f;

    top->bx = bottom->bx = -1.f;
    top->by = bottom->by = 0.f;

    top->cx = bottom->cx = 1.f;
    top->cy = bottom->cy = 0.f;

    bottom->ax = 0.f;
    bottom->ay = -1.f;
}
