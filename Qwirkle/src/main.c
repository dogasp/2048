#include <SDL2/SDL.h>
#include <stdio.h>
#include "../headers/types.h"
#include "../headers/graphics.h"

int main(int argc, char** argv)
{
    Pawn empty = {'a', 'a'};
    int height = 500, cellCount = 25, cellSize = height/cellCount;
    Pawn grid[cellCount][cellCount];
    for (int i = 0; i < cellCount; i ++){
        for (int j = 0; j < cellCount; j++){
            grid[i][j] = empty;
            if (i == 1 && j == 0){
                Pawn test = {'r', 'x'};
                grid[i][j] = test;
            }
        }
    }
    SDL_Window* window = NULL;
    window = SDL_CreateWindow("Jeu Qwirkle",SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, height + height / 5, height, SDL_WINDOW_SHOWN);

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
        PrintGrid(renderer, cellCount, grid, cellSize);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}