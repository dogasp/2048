#include <SDL2/SDL.h>
#include <stdio.h>

int main(int argc, char** argv)
{

    SDL_Window* window = NULL;
    window = SDL_CreateWindow("Jeu 2048",SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

    int continuer = 1;
    SDL_Event event;

    while (continuer){
        SDL_PollEvent(&event);
        switch (event.type){
            case SDL_QUIT:
                continuer = 0;
                break;
        }
    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}