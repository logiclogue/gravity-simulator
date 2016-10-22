#include <GL/glu.h>
#include "Drawer.h"
#include "Frame.h"
#include "Camera.h"
#include "DrawableParticle.h"
#include "DrawableUniverse.h"


int main(void)
{
    Camera *camera = Camera_new();
    Frame *frame = Frame_new(camera);
    Drawer *drawer = Drawer_new(camera, frame);
    DrawableParticle *particle_a = DrawableParticle_new(drawer);
    DrawableParticle *particle_b = DrawableParticle_new(drawer);
    Universe *universe = DrawableUniverse_new();
    float x = 0;

    DrawableUniverse_add(universe, particle_a);
    DrawableUniverse_add(universe, particle_b);

    while (!frame->is_exit) {
        camera->y = 0.2 * x;

        DrawableParticle_set_x(particle_a, 0.2 * x);
        DrawableParticle_set_mass(particle_a, x);

        DrawableUniverse_test(universe);
        Frame_draw(frame);
        Drawer_clear(drawer);
        Frame_event_loop(frame);

        x += 0.01;
    }

    return 0;
}
