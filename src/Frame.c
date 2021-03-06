#include <SDL2/SDL.h>
#include <GL/glu.h>
#include <stdio.h>
#include "Frame.h"


static int initGL(void);
static int initSDL(Frame *self);


Frame *Frame_new(Camera *camera)
{
    Frame *self = malloc(sizeof(Frame));

    self->is_exit = 0;
    self->title = "Gravity Simulator";
    self->event = malloc(sizeof(SDL_Event));
    self->camera = camera;

    Frame_resize(self, 640, 480);
    initSDL(self);
    initGL();

    return self;
}

void Frame_quit(Frame *self)
{
    SDL_DestroyWindow(self->window);
    SDL_GL_DeleteContext(self->context);
    SDL_Quit();
}

void Frame_draw(Frame *self)
{
    SDL_GL_SwapWindow(self->window);
}

void Frame_event_loop(Frame *self)
{
    SDL_PollEvent(self->event);

    switch (self->event->window.event) {
    case SDL_WINDOWEVENT_CLOSE:
        self->is_exit = 1;

        Frame_quit(self);

        break;

    case SDL_WINDOWEVENT_RESIZED:
        Frame_resize(self,
            self->event->window.data1, self->event->window.data2);

        break;

    default:
        break;
    }
}

void Frame_resize(Frame *self, int width, int height)
{
    self->width = width;
    self->height = height;

    if (width > height) {
        self->width_unit = (float)height / (float)width;
        self->height_unit = 1.f;
    } else {
        self->width_unit = 1.f;
        self->height_unit = (float)width / (float)height;
    }

    self->width_unit *= self->camera->zoom;
    self->height_unit *= self->camera->zoom;

    glViewport(0, 0, width, height);
}


static int initSDL(Frame *self)
{
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("SDL_Init Error: %s\n", SDL_GetError());

        return 1;
    }

    self->window = SDL_CreateWindow(
        self->title,
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        self->width, self->height,
        SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN
    );

    if (self->window == NULL) {
        printf("SDL_CreateWindow Error: %s", SDL_GetError());
        SDL_Quit();
        
        return 1;
    }

    self->context = SDL_GL_CreateContext(self->window);

    if (self->context == NULL) {
        printf(
            "OpenGL context could not be created! SDL Error: %s\n",
            SDL_GetError()
        );

        return 1;
    }

    if (SDL_GL_SetSwapInterval(1) < 0) {
        printf("Warning: Unable to set VSync! SDL Error: %s\n", SDL_GetError());

        return 1;
    }
    
    return 0;
}

static int initGL(void)
{
    GLenum error = GL_NO_ERROR;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClearColor(0.f, 0.f, 0.f, 1.f);

    error = glGetError();

    if (error != GL_NO_ERROR) {
        printf("Error initialising OpenGL! %s\n", gluErrorString(error));

        return 0;
    }
    
    return 1;
}
