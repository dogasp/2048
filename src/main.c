#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include "../headers/function.h"
#include "../headers/graphics.h"

int main(int argc, char** argv)
{

    int nb_players = nb_players_Message();    //Solo or Multijoueur
    int Game_mode_multi = 1;
    if (nb_players== 2) Game_mode_multi = Game_mode_multi_Message(); //if Multi: IA or Player IRL
    int Game_mode_3 = Game_mode_3_Message(Game_mode, Game_mode_multi); // Time limited or the faster or free
    int Game_size_grid = Game_size_grid_Message(Game_mode);


    int gridSize;
    if (Game_size_grid == 4) gridSize =4;
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

    //initialisation de la fenetre et de la police



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
