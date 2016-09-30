#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <stdio.h>

int main(void)
{
    SDL_Window *window;
    SDL_Renderer *renderer;
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

    int i;

    for (i = 0; i < 10000; i++) {
        rect.x = i / 100;
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderFillRect(renderer, &rect);
        SDL_RenderPresent(renderer);
    }
    
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
