#ifndef _DRAWER_H_
#define _DRAWER_H_

#include <SDL2/SDL.h>


typedef struct DrawerTag {
    int width;
    int height;
    SDL_Window *window;
    SDL_GLContext *context;
} Drawer;


Drawer *Drawer_main(void);
void Drawer_quit(Drawer *);
void Drawer_draw(Drawer *self);
void Drawer_triangle(
    float ax, float ay,
    float bx, float by,
    float cx, float cy);
void Drawer_clear(void);

#endif
