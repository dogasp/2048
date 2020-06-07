#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <time.h>
#include "../headers/function.h"
#include "../headers/graphics.h"

int main(int argc, char** argv)
{

    int nb_players = nb_players_Message();    //Solo or Multijoueur
    int Game_mode_multi = 1;
    if (nb_players== 2) Game_mode_multi = Game_mode_multi_Message(); //if Multi: IA or Player IRL
    //int Game_mode_3 = Game_mode_3_Message(nb_players, Game_mode_multi); // Time limited or the faster or free
	int gridSize = 4;
    if (nb_players== 1) gridSize = Game_size_grid_Message(nb_players);

    int grid[2][gridSize][gridSize];
    for (int k = 0; k < 2; k++){
      for (int i = 0; i < gridSize; i ++){
          for (int j = 0; j < gridSize; j ++){
              grid[k][i][j] = 0;
          }
      }
    }

    //tirage de deux cases au hasard
    for (int i = 0; i < 2; i ++){
		for (int j = 0; j < 2; j++){
			randomPicker(gridSize, grid[i]);
		}
    }

    //initialisation de la fenetre et de la police

    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();

    int Height = 480;

    SDL_Window* window = NULL;
	int delta = (nb_players == 2)?2:1;
    window = SDL_CreateWindow("Jeu 2048",SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, Height*1.2*delta, Height*1.3, SDL_WINDOW_SHOWN);

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

    int continuer = 1, canclick = 0;
	time_t start = time(NULL);
	char timer[50] = "temps restant: sec";
	SDL_Point TimerPoint = {Height/2, Height*1.1};
    int playerTurn;

    int activated = 0;
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
                        activated = 1;
                        int result1 = moveRight(gridSize, grid[0]);
                        if (result1){
                          randomPicker(gridSize, grid[0]);
                          }
                        else{
                          valid_random(gridSize, grid[0]);
                        }
                    }
                    else if (event.key.keysym.sym == SDLK_DOWN){
                        activated = 1;
                        int result2 = moveDown(gridSize, grid[0]);
                        if (result2){
                          randomPicker(gridSize, grid[0]);
                        }
                        else{
                          valid_random(gridSize, grid[0]);
                        }
                    }
                    else if (event.key.keysym.sym == SDLK_LEFT){
                        activated = 1;
                        int result3 = moveLeft(gridSize, grid[0]);
                        if (result3){
                          randomPicker(gridSize, grid[0]);
                        }
                        else{
                          valid_random(gridSize, grid[0]);
                        }
                    }
                    else if (event.key.keysym.sym == SDLK_UP){
                        activated = 1;
                        int result4 = moveUp(gridSize, grid[0]);
                        if (result4){
                          randomPicker(gridSize, grid[0]);
                        }
                        else{
                          valid_random( gridSize, grid[0]);
                        }
                    }
                }
                canclick = 0;
                if (activated == 1) playerTurn = (playerTurn + 1)%nb_players;
                activated = 0;
                break;
        }

		resetScreen(renderer);
		time_t current = time(NULL);
		int SecTimer =  current - start;
		sprintf(timer, "Temps restant: %d sec", 300 -SecTimer);
		printText(timer, renderer, TimerPoint);

        printGrid(renderer, Height, gridSize, grid[0], 0);
        if (nb_players == 2) printGrid(renderer, Height, gridSize, grid[1], 1);
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
