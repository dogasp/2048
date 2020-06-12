#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <string.h>


char * rules = "But du jeu"; 

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

void resetScreen(SDL_Renderer * renderer){
    SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);
    SDL_RenderFillRect(renderer, NULL);
}

void printGrid(SDL_Renderer * renderer, int Height, int gridSize, int grid[gridSize][gridSize], int second){
    int interval = Height/gridSize;
    int gap = 10;

    SDL_Color Backcolor = {200, 200, 200, 255};
    SDL_SetRenderDrawColor(renderer, Backcolor.r, Backcolor.g, Backcolor.b, Backcolor.a);
    SDL_Rect r = {Height*second*1.4, 0, Height, Height};
    SDL_RenderFillRect(renderer, &r);

    SDL_Color LineColor = {125, 125, 125, 255};
    SDL_SetRenderDrawColor(renderer, LineColor.r, LineColor.g, LineColor.b, LineColor.a);
    for (int i = 0; i < gridSize + 1; i ++){
        SDL_Rect rect = {interval * i - gap/2 + Height*second*1.4, 0, gap, Height};
        SDL_RenderFillRect(renderer, &rect);
    }

    for (int i = 0; i < gridSize + 1; i ++){
        SDL_Rect rect = {Height*second*1.4, interval * i - gap/2, Height, gap};
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
                SDL_Rect rect = {interval * i + gap/2 + Height*second*1.4, interval * j + gap/2, interval - gap, interval - gap};
                SDL_RenderFillRect(renderer, &rect);
                SDL_Point location = {interval * i + interval/2, interval * j + interval/2};
                char str[6];
                sprintf(str, "%d", grid[i][j]);
                printText(str, renderer, location);
            }
        }
    }

}
// hello
int nb_players_Message(){
  //affichage des règles
  SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Règles du jeu de traverse", rules, NULL);
  //data des boutons
  const SDL_MessageBoxButtonData buttons[] = {
      { 0, 1, "Solo" },
      { 0, 2, "Multijoueur" },
  };
  //couleurs
  const SDL_MessageBoxColorScheme colorScheme = {
      {
          { 255,   0,   0 },
          {   0, 255,   0 },
          { 255, 255,   0 },
          {   0,   0, 255 },
          { 255,   0, 255 }
      }
  };
  //nom de la fenètre, ombre de boutons ...
  const SDL_MessageBoxData messageboxdata = {
      SDL_MESSAGEBOX_INFORMATION, /* .flags */
      NULL, /* .window */
      "Mode de Jeu", /* .title */
      "Choisis entre le mode Solo ou Multijoueur ?", /* .message */
      SDL_arraysize(buttons), /* .numbuttons */
      buttons, /* .buttons */
      &colorScheme /* .colorScheme */
  };
  int buttonid;
  SDL_ShowMessageBox(&messageboxdata, &buttonid); //affichage de la boite de dialogue
  if (buttonid == -1) buttonid = 0;
  return buttonid ; //renvois du résultat

}

int Game_mode_multi_Message(){
    const SDL_MessageBoxButtonData buttons[] = {
        { 0, 0, "Joueur 2" },
        { 0, 1, "IA" },

    };
    const SDL_MessageBoxColorScheme colorScheme = {
        {
            { 255,   0,   0 },
            {   0, 255,   0 },
            { 255, 255,   0 },
            {   0,   0, 255 },
            { 255,   0, 255 }
        }
    };

    const SDL_MessageBoxData messageboxdata = {
        SDL_MESSAGEBOX_INFORMATION, // .flags
        NULL, // .window
        "Type de joueur", // .title
        "Joueur 2 ou IA", // .message
        SDL_arraysize(buttons), /* .numbuttons */
        buttons, // .buttons
        &colorScheme // .colorScheme
      };
    int buttonid;
    SDL_ShowMessageBox(&messageboxdata, &buttonid);
    if (buttonid == -1) buttonid = 0;
    return buttonid;
}

int Game_mode_3_Message(int Game_mode, int Game_mode_multi){
  int x;
  if (Game_mode == 1){
    x = 1;
  }
  else if (Game_mode == 2){
    if (Game_mode_multi == 0){
      x = 0;
    }
    else if(Game_mode_multi == 1){
      x = 2;
    }
  }
  const SDL_MessageBoxButtonData buttons[] = {
      { 0, 0, "Mode libre" },
      { 0, 1, "Temps limité" },
      { 0, 2, "Course" }

  };
  const SDL_MessageBoxColorScheme colorScheme = {
      {
          { 255,   0,   0 },
          {   0, 255,   0 },
          { 255, 255,   0 },
          {   0,   0, 255 },
          { 255,   0, 255 }
      }
  };
  const SDL_MessageBoxData messageboxdata = {
      SDL_MESSAGEBOX_INFORMATION, // .flags
      NULL, // .window
      "Bite", // .title
      "essai", // .message
      3 - x,
      buttons, // .buttons
      &colorScheme // .colorScheme
    };

  int buttonid;
  SDL_ShowMessageBox(&messageboxdata, &buttonid);
  if (buttonid == -1) buttonid = 0;
  return buttonid;

}

int Game_size_grid_Message(int Game_mode){
  int x;
  if (Game_mode == 1) x = 0;
  else x = 1;
  const SDL_MessageBoxButtonData buttons[] = {
      { 0, 4, "4x4" },
      { 0, 8, "8x8" },

  };
  const SDL_MessageBoxColorScheme colorScheme = {
      {
          { 255,   0,   0 },
          {   0, 255,   0 },
          { 255, 255,   0 },
          {   0,   0, 255 },
          { 255,   0, 255 }
      }
  };
  const SDL_MessageBoxData messageboxdata = {
      SDL_MESSAGEBOX_INFORMATION, // .flags
      NULL, // .window
      "Taille de la Grille", // .title
      "Choisis ta grille, le 8x8 n'est disponible qu'en Solo", // .message
      2 - x,
      buttons, // .buttons
      &colorScheme // .colorScheme
    };

  int buttonid;
  SDL_ShowMessageBox(&messageboxdata, &buttonid);
  if (buttonid == -1) buttonid = 0;
  return buttonid;

}
