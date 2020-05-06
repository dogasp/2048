#include <SDL2/SDL.h>

#include <stdio.h>

int main(int argc, char** argv)
{

    SDL_Window* window = NULL;
    window = SDL_CreateWindow("Jeu 2048",SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);

    SDL_Delay(3000); /* Attendre trois secondes, que l'utilisateur voie la fenêtre */

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}