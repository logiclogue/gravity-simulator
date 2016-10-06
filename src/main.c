#include <GL/glu.h>
#include "Drawer.h"
#include "Frame.h"
#include "Camera.h"


static void draw(Drawer *drawer, float x);


int main(void)
{
    Camera *camera = Camera_main();
    Frame *frame = Frame_main(camera);
    Drawer *drawer = Drawer_main(camera, frame);

    float x = 0;

    while (!frame->is_exit) {
        camera->y = 0.2 * x;

        draw(drawer, x);
        Frame_draw(frame);
        Drawer_clear(drawer);
        Frame_event_loop(frame);

        x += 0.01;
    }

    return 0;
}


static void draw(Drawer *drawer, float x)
{
    Drawer_draw_triangle(drawer,
        x + 0.f, 1.f,
        x + -1.f, 0.f,
        x + 1.f, 0.f
    );
    Drawer_draw_triangle(drawer,
        x + 0.f, -1.f,
        x + -1.f, 0.f,
        x + 1.f, 0.f
    );
}
