#include <GL/glu.h>
#include "Frame.h"


static void draw(Frame *frame, float x);
static void draw_triangle(Frame *frame,
    float ax, float ay,
    float bx, float by,
    float cx, float cy);
static void clear(void);


int main(void)
{
    Frame *frame = Frame_main();

    float x;

    while (!frame->is_exit) {
        draw(frame, x);
        Frame_draw(frame);
        clear();
        Frame_event_loop(frame);

        //x += 0.0001;
    }

    return 0;
}


static void draw(Frame *frame, float x)
{
    draw_triangle(frame,
        x + 0.f, 1.f,
        x + -1.f, 0.f,
        x + 1.f, 0.f
    );
    draw_triangle(frame,
        x + 0.f, -1.f,
        x + -1.f, 0.f,
        x + 1.f, 0.f
    );
}

static void draw_triangle(Frame *frame,
    float ax, float ay,
    float bx, float by,
    float cx, float cy)
{
    float xu = frame->width_unit;
    float yu = frame->height_unit;

    glBegin(GL_TRIANGLES);
        glVertex2f(ax * xu, ay * yu);
        glVertex2f(bx * xu, by * yu);
        glVertex2f(cx * xu, cy * yu);
    glEnd();
}

static void clear(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
}
