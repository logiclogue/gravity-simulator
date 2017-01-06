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
    float zoom = -2;

    DrawableParticle_set_x(particle_b, 1);
    DrawableParticle_set_y(particle_b, 1);
    DrawableParticle_set_y(particle_c, 5);
    DrawableParticle_set_mass(particle_a, 2);

    DrawableUniverse_add(universe, particle_a);
    DrawableUniverse_add(universe, particle_b);
    DrawableUniverse_add(universe, particle_c);

    particle_b->particle->velocity->x = 0.05;

    while (!frame->is_exit) {
        Camera_set_zoom(camera, zoom);
        Frame_resize(frame, frame->width, frame->height);

        DrawableUniverse_test(universe);
        Frame_draw(frame);
        Drawer_clear(drawer);
        Frame_event_loop(frame);

        zoom -= 0.0005;
    }

    return 0;
}
