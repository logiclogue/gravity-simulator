#include "Drawer.h"


static void draw(float x);


int main(void)
{
    Drawer *drawer = Drawer_main();

    float x;

    while (!drawer->is_exit) {
        draw(x);
        Drawer_draw(drawer);
        Drawer_clear();
        Drawer_event_loop(drawer);

        x += 0.01;
    }

    return 0;
}


static void draw(float x)
{
    Drawer_triangle(
        x + 0.f, 1.f,
        x + -1.f, -1.f,
        x + 1.f, -1.f
    );
}
