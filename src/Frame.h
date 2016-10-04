#ifndef _FRAME_H_
#define _FRAME_H_

#include <SDL2/SDL.h>
#include "Camera.h"


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
    Camera *camera;
} Frame;


Frame *Frame_main(Camera *);
void Frame_quit(Frame *);
void Frame_draw(Frame *);
void Frame_event_loop(Frame *);

#endif

typedef struct FrameTag Frame;
