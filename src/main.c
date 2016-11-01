#include <GL/glu.h>
#include "Drawer.h"
#include "Frame.h"
#include "Camera.h"
#include "DrawableParticle.h"
#include "DrawableUniverse.h"
#include "Gravity.h"


int main(void)
{
    Camera *camera = Camera_new();
    Frame *frame = Frame_new(camera);
    Drawer *drawer = Drawer_new(camera, frame);
    DrawableParticle *particle_a = DrawableParticle_new(drawer);
    DrawableParticle *particle_b = DrawableParticle_new(drawer);
    DrawableParticle *particle_c = DrawableParticle_new(drawer);
    Universe *universe = DrawableUniverse_new();
    float x = 0;

    DrawableParticle_set_x(particle_b, 1);
    DrawableParticle_set_y(particle_b, 1);
    DrawableParticle_set_x(particle_c, -5);

    DrawableUniverse_add(universe, particle_a);
    DrawableUniverse_add(universe, particle_b);
    DrawableUniverse_add(universe, particle_c);

    while (!frame->is_exit) {
        camera->y = 0.02 * x;

        Camera_set_zoom(camera, -3);
        Frame_resize(frame, frame->width, frame->height);

        DrawableUniverse_test(universe);
        Frame_draw(frame);
        Drawer_clear(drawer);
        Frame_event_loop(frame);

        x += 0.01;
    }

    return 0;
}
