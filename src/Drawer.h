#ifndef _DRAWER_H_
#define _DRAWER_H_

#include <SDL2/SDL.h>


typedef struct DrawerTag {
    int width;
    int height;
    int is_exit;
    char *title;
    SDL_Window *window;
    SDL_GLContext *context;
    SDL_Event *event;
} Drawer;


Drawer *Drawer_main(void);
void Drawer_quit(Drawer *);
void Drawer_draw(Drawer *);
void Drawer_clear(void);
void Drawer_event_loop(Drawer *);

#endif
