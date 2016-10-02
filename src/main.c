#include <GL/glu.h>
#include "Frame.h"


static void draw(float x);
static void draw_triangle(
    float ax, float ay,
    float bx, float by,
    float cx, float cy);
static void clear(void);


int main(void)
{
    Frame *frame = Frame_main();

    float x;

    while (!frame->is_exit) {
        draw(x);
        Frame_draw(frame);
        clear();
        Frame_event_loop(frame);

        x += 0.01;
    }

    return 0;
}


static void draw(float x)
{
    draw_triangle(
        x + 0.f, 1.f,
        x + -1.f, -1.f,
        x + 1.f, -1.f
    );
}

static void draw_triangle(
    float ax, float ay,
    float bx, float by,
    float cx, float cy)
{
    glBegin(GL_TRIANGLES);
        glVertex2f(ax, ay);
        glVertex2f(bx, by);
        glVertex2f(cx, cy);
    glEnd();
}

static void clear(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
}
