#include <GL/glu.h>
#include "Drawer.h"
#include "Frame.h"
#include "Camera.h"
#include "Circle.h"
#include "Universe.h"
#include "DrawableParticle.h"


int main(void)
{
    Camera *camera = Camera_new();
    Frame *frame = Frame_new(camera);
    Drawer *drawer = Drawer_new(camera, frame);
    Circle *circle = Circle_new(drawer);
    Universe *universe = Universe_new();
    DrawableParticle *drawable_particle = DrawableParticle_new(drawer);

    float x = 0;

    Universe_add(universe, drawable_particle->particle);
    Universe_destroy(universe);

    while (!frame->is_exit) {
        camera->y = 0.2 * x;

        Circle_draw(circle);
        Frame_draw(frame);
        Drawer_clear(drawer);
        Frame_event_loop(frame);

        Circle_set_x(circle, 0.9 * -x);

        x += 0.01;
    }

    return 0;
}
