#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "../headers/types.h"
#include <string.h>

void PrintGrid(SDL_Renderer * renderer, int cellCount, Pawn grid[cellCount][cellCount], int cellSize){
    
    for (int i = 0; i < cellCount; i ++){
        for (int j = 0; j < cellCount; j ++){
            char * color, * shape;
            switch (grid[i][j].color){
                case 'r':
                    color = "red";
                    break;
                case 'b':
                    color = "blue";
                    break;
                case 'o':
                    color = "orange";
                    break;
                case 'm':
                    color = "purple";
                    break;
                case 'j':
                    color = "yellow";
                    break;
                case 'v':
                    color = "green";
                    break;
            };
            switch (grid[i][j].shape){
                case 'x':
                    shape = "cross";
                    break;
                case 'l':
                    shape = "losange";
                    break;
                case 'e':
                    shape = "star";
                    break;
                case 'r':
                    shape = "square";
                    break;
                case 't':
                    shape = "clover";
                    break;
                case 'c':
                    shape = "circle";
                    break;
            };
            printf("%s %s\n", shape, color);
            char link[50];
            sprintf(link, "res/dir_images/%s_%s.png", shape, color);
            SDL_Surface * image = IMG_Load(link);
            SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, image);
            SDL_Rect pos = {i*cellSize, j*cellSize, cellSize, cellSize}; //position du pion
            SDL_RenderCopy(renderer, texture, NULL, &pos); //ajout de l'image sur le renderer
            SDL_DestroyTexture(texture);
            SDL_FreeSurface(image);
        }
    }
}