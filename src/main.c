#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <GL/glu.h>
#include <stdio.h>


typedef int bool;
enum {
    false, true
};

bool initGL(void)
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

        return false;
    }
    
    return true;
}

void render(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_QUADS);
        glVertex2f(-0.5f, -0.5f);
        glVertex2f(0.5f, -0.5f);
        glVertex2f(0.5f, 0.5f);
        glVertex2f(-0.5f, 0.5f);
    glEnd();
}

int main(void)
{
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_GLContext context;
    SDL_Rect rect = {
        0, 0, 100, 100
    };

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("SDL_Init Error: %s\n", SDL_GetError());

        return 1;
    }

    window = SDL_CreateWindow(
        "Hello World",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        640, 480,
        SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN
    );
    renderer = SDL_CreateRenderer(window, -1, 0);

    if (window == NULL) {
        printf("SDL_CreateWindow Error: %s", SDL_GetError());
        SDL_Quit();
        
        return 1;
    }

    context = SDL_GL_CreateContext(window);

    if (context == NULL) {
        printf("OpenGL context could not be created! SDL Error: %s\n", SDL_GetError());

        return 1;
    }

    if (SDL_GL_SetSwapInterval(1) < 0) {
        printf("Warning: Unable to set VSync! SDL Error: %s\n", SDL_GetError());

        return 1;
    }

    if (!initGL()) {
        printf("Unable to initialise OpenGL!\n");
    }

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);
    //SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    //SDL_RenderFillRect(renderer, &rect);
    render();
    SDL_RenderPresent(renderer);

    
    SDL_Delay(1000);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
