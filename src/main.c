#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include "../headers/function.h"
#include "../headers/graphics.h"

int main(int argc, char** argv)
{

    int Game_mode = Game_mode_Message();    //Solo or Multijoueur
    int Game_mode_2 = 0;
    if (Game_mode == 2) Game_mode_2 = Game_mode_2_Message(); //if Multi: IA or Player IRL
    int Game_mode_3 = Game_mode_3_Message(Game_mode, Game_mode_2); // Time limited or the faster or free
    int Game_size_grid = Game_size_grid_Message(Game_mode);


    int gridSize;
    if (Game_size_grid == 0) gridSize =4;
    else gridSize =8;
    int grid[gridSize][gridSize];
    for (int i = 0; i < gridSize; i ++){
        for (int j = 0; j < gridSize; j ++){
            grid[i][j] = 0;
        }
    }

    //tirage de deux cases au hasard
    for (int i = 0; i < 2; i ++){
        randomPicker(gridSize, grid);
    }

    grid[0][0] = 4;
    grid[3][3] = 8192;
    grid[1][3] = 128;
    grid[2][3] = 512;
    grid[3][3] = 8192;
    grid[0][3] = 4096;


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
                        int result1 = moveRight(gridSize, grid);
                        if (result1){
                          randomPicker(gridSize, grid);
                          }
                        else{
                          valid_random(gridSize, grid);
                        }
                    }
                    else if (event.key.keysym.sym == SDLK_DOWN){
                        int result2 = moveDown(gridSize, grid);
                        if (result2){
                          randomPicker(gridSize, grid);
                        }
                        else{
                          valid_random(gridSize, grid);
                        }
                    }
                    else if (event.key.keysym.sym == SDLK_LEFT){
                        int result3 = moveLeft(gridSize, grid);
                        if (result3){
                          randomPicker(gridSize, grid);
                        }
                        else{
                          valid_random(gridSize, grid);
                        }
                    }
                    else if (event.key.keysym.sym == SDLK_UP){
                        int result4 = moveUp(gridSize, grid);
                        if (result4){
                          randomPicker(gridSize, grid);
                        }
                        else{
                          valid_random( gridSize, grid);
                        }
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
