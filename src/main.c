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
    //DrawableParticle *particle = DrawableParticle_new(drawer);
    Universe *universe = DrawableUniverse_new();
    float x = 0;

    DrawableUniverse_add(universe, DrawableParticle_new(drawer));
    DrawableUniverse_add(universe, DrawableParticle_new(drawer));

    while (!frame->is_exit) {
        camera->y = 0.2 * x;

        DrawableUniverse_test(universe);
        Frame_draw(frame);
        Drawer_clear(drawer);
        Frame_event_loop(frame);

        x += 0.01;
    }

    return 0;
}
