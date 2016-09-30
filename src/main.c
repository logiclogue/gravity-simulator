#include <SDL2/SDL.h>
#include <stdio.h>

int main(void)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("SDL_Init Error: %s\n", SDL_GetError());

        return 1;
    }

    SDL_Window *window = SDL_CreateWindow(
        "Hello World",
        100, 100, 640, 480,
        SDL_WINDOW_SHOWN
    );

    if (window == NULL) {
        printf("SDL_CreateWindow Error: %s", SDL_GetError());
        SDL_Quit();
        
        return 1;
    }

    SDL_Delay(10001);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
