#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include "../headers/function.h"
#include "../headers/graphics.h"

int main(int argc, char** argv)
{
    int gridSize = 4;
    int grid[gridSize][gridSize];
    for (int i = 0; i < gridSize; i ++){
        for (int j = 0; j < gridSize; j ++){
            grid[i][j] = 0;
        }
    }

    //tirage de deux cases au hasard
    /*for (int i = 0; i < 2; i ++){
        randomPicker(gridSize, grid);
    }*/
    grid[0][0] = 2;
    grid[3][0] = 2;

    
    //initialisation de la fenetre et de la police
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();

    int Height = 480;

    SDL_Window* window = NULL;
    window = SDL_CreateWindow("Jeu 2048",SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, Height*1.3, Height, SDL_WINDOW_SHOWN);

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

    int continuer = 1, canclick = 0;
    SDL_Event event;

    while (continuer){
        SDL_PollEvent(&event);
        switch (event.type){
            case SDL_QUIT:
                continuer = 0;
                break;
            case SDL_KEYDOWN:
                canclick = 1;
                break;
            case SDL_KEYUP:
                if (canclick == 1){
                    if (event.key.keysym.sym == SDLK_RIGHT){
                        moveRight(gridSize, grid);
                        randomPicker(gridSize, grid);
                    }
                    else if (event.key.keysym.sym == SDLK_DOWN){
                        moveDown(gridSize, grid);
                        randomPicker(gridSize, grid);
                    }
                    else if (event.key.keysym.sym == SDLK_LEFT){
                        moveLeft(gridSize, grid);
                        randomPicker(gridSize, grid);
                    }
                    else if (event.key.keysym.sym == SDLK_UP){
                        moveUp(gridSize, grid);
                        randomPicker(gridSize, grid);
                    }
                }
                canclick = 0;
                break;
        }
        printGrid(renderer, Height, gridSize, grid);
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}