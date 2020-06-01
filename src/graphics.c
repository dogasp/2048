#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <string.h>

void printText(char * text, SDL_Renderer * renderer, SDL_Point pos){
    SDL_Color couleur = {0, 0, 0}; //sélection par défaut de la couleur
    if (strcmp(text,"2") && strcmp(text,"4")){
        couleur.r = 255;
        couleur.g = 255;
        couleur.b = 255;
    }
    //récupération de la police d'écriture
    TTF_Font* font = TTF_OpenFont("res/ClearSans.ttf", 30);
    SDL_Rect Message_rect; //rectange d'affichage

    SDL_Surface* surfaceMessage = TTF_RenderText_Solid(font, text, couleur); //surface où se trouvera le texte

    Message_rect.x = pos.x - surfaceMessage->w/2; //calcul de la taille du rectangle suivant la taille du texte
    Message_rect.y = pos.y - surfaceMessage->h/2;
    
    Message_rect.w = surfaceMessage->w; 
    Message_rect.h = surfaceMessage->h;

    SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage); //création de la texture du texte et ajout au renderer
    SDL_SetTextureBlendMode(Message, SDL_BLENDMODE_BLEND);
    SDL_SetTextureAlphaMod(Message, 220);
    SDL_RenderCopy(renderer, Message, NULL, &Message_rect);
    TTF_CloseFont(font); //libération de l'espace mémoire
    SDL_FreeSurface(surfaceMessage);
    SDL_DestroyTexture(Message);
}


void printGrid(SDL_Renderer * renderer, int Height, int gridSize, int grid[gridSize][gridSize]){
    int interval = Height/gridSize;
    int gap = 10;

    SDL_Color Backcolor = {200, 200, 200, 255};
    SDL_SetRenderDrawColor(renderer, Backcolor.r, Backcolor.g, Backcolor.b, Backcolor.a);
    SDL_RenderFillRect(renderer, NULL);

    SDL_Color LineColor = {125, 125, 125, 255};
    SDL_SetRenderDrawColor(renderer, LineColor.r, LineColor.g, LineColor.b, LineColor.a);
    for (int i = 0; i < gridSize + 1; i ++){
        SDL_Rect rect = {interval * i - gap/2, 0, gap, Height};
        SDL_RenderFillRect(renderer, &rect);
    }

    for (int i = 0; i < gridSize + 1; i ++){
        SDL_Rect rect = {0, interval * i - gap/2, Height, gap};
        SDL_RenderFillRect(renderer, &rect);
    }    

    for (int i = 0; i < gridSize; i ++){
        for (int j = 0; j < gridSize; j ++){
            if (grid[i][j] != 0){
                switch (grid[i][j]){
                    case 2:
                        SDL_SetRenderDrawColor(renderer, 252, 252, 252, 150);
                        break;
                    case 4:
                        SDL_SetRenderDrawColor(renderer, 255, 245, 204, 150);
                        break;                    
                    case 8:
                        SDL_SetRenderDrawColor(renderer, 235, 166, 66, 150);
                        break;
                    case 16:
                        SDL_SetRenderDrawColor(renderer, 235, 145, 66, 150);
                        break;
                    case 32:
                        SDL_SetRenderDrawColor(renderer, 235, 117, 66, 150);
                        break;                    
                    case 64:
                        SDL_SetRenderDrawColor(renderer, 226, 76, 76, 150);
                        break;                    
                    case 128:
                        SDL_SetRenderDrawColor(renderer, 248, 233, 122, 150);
                        break;                    
                    case 256:
                        SDL_SetRenderDrawColor(renderer, 245, 234, 99, 150);
                        break;                    
                    case 512:
                        SDL_SetRenderDrawColor(renderer, 255, 233, 45, 150);
                        break;
                    case 1024:
                        SDL_SetRenderDrawColor(renderer, 255, 233, 45, 150);
                        break;
                    case 2048:
                        SDL_SetRenderDrawColor(renderer, 211, 103, 189, 150);
                        break;
                    case 4096:
                        SDL_SetRenderDrawColor(renderer, 208, 140, 234, 150);
                        break;
                    case 8192:
                        SDL_SetRenderDrawColor(renderer, 184, 0, 255, 150);
                        break;
                }
                //SDL_SetRenderDrawColor(renderer, Backcolor.r, Backcolor.g, Backcolor.b, 150);
                SDL_Rect rect = {interval * i + gap/2, interval * j + gap/2, interval - gap, interval - gap};
                SDL_RenderFillRect(renderer, &rect);
                SDL_Point location = {interval * i + interval/2, interval * j + interval/2};
                char str[6];
                sprintf(str, "%d", grid[i][j]);
                printText(str, renderer, location);
            }
        }
    }

}