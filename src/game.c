#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>


int GameMode(int nb_players, int Game_mode_multi, int Game_mode_3, int Game_size_grid)
{

  SDL_Init(SDL_INIT_VIDEO);
  TTF_Init();

  int Height = 480;

  SDL_Window* window = NULL;
  if (nb_players == 2) Height = Height*2;
  window = SDL_CreateWindow("Jeu 2048",SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, Height*1.3, Height*1.3, SDL_WINDOW_SHOWN);

  SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

  int continuer = 1, canclick = 0;
  SDL_Event event;


}
