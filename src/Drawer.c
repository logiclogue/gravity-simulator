#include <SDL2/SDL.h>
#include <GL/glu.h>
#include <stdio.h>
#include "Drawer.h"


static int initGL(void);
static int initSDL(Drawer *self);


Drawer *Drawer_main(void)
{
    Drawer *self = malloc(sizeof(Drawer));

    self->width = 640;
    self->height = 480;
    self->is_exit = 0;
    self->title = "Gravity Simulator";
    self->event = malloc(sizeof(SDL_Event));

    initSDL(self);
    initGL();

    return self;
}

void Drawer_quit(Drawer *self)
{
    SDL_DestroyWindow(self->window);
    SDL_GL_DeleteContext(self->context);
    SDL_Quit();
}

void Drawer_draw(Drawer *self)
{
    SDL_GL_SwapWindow(self->window);
}

void Drawer_triangle(
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

void Drawer_clear(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
}

void Drawer_event_loop(Drawer *self)
{
    SDL_PollEvent(self->event);

    switch (self->event->window.event) {
    case SDL_WINDOWEVENT_CLOSE:
        self->is_exit = 1;

        Drawer_quit(self);

        break;

    default:
        break;
    }
}


static int initSDL(Drawer *self)
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
