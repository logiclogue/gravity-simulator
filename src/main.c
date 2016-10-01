#include "Drawer.h"


static void draw(float x);


int main(void)
{
    Drawer *drawer = Drawer_main();

    float x;

    for (x = 0; x < 2; x += 0.01) {
        draw(x);
        Drawer_draw(drawer);
        Drawer_clear();
    }

    Drawer_quit(drawer);

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
