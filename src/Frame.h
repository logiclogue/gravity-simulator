#ifndef _DRAWER_H_
#define _DRAWER_H_

#include <SDL2/SDL.h>


typedef struct FrameTag {
    int width;
    int height;
    float width_unit;
    float height_unit;
    int is_exit;
    char *title;
    SDL_Window *window;
    SDL_GLContext *context;
    SDL_Event *event;
} Frame;


Frame *Frame_main(void);
void Frame_quit(Frame *);
void Frame_draw(Frame *);
void Frame_event_loop(Frame *);

#endif
