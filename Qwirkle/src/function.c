#include <stdio.h>
#include <math.h>
#include <SDL2/SDL2.h>
#include "../headers/types.h"

/*Fonciton qui renvoie toutes les possibilitées de coups à jouer d'un pion dans la grille*/
int PossibleMove(int cellCount, Pawn grid[cellCount][cellCount], SDL_Point MousePoint, Pawn ToCheck, , Pawn *Moves){

    int array_cells[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
    int array_cells_2[4][2] = {{0,0},{0,0},{0,0},{0,1}};

    for (int i =0; i<cellCount;i++){
        for (int j=0; j<cellCount;j++){
            if (grid[i][j] == {'a', 'a'}){
                int nb_cells = 0;
                for (int a=0;a<4;a++){
                    if (grid[i+array_cells[a][0]][j+array_cells[a][1]] != {'a', 'a'}{
                        nb_cells ++;

                        switch (nb_cells){
                            case 0:
                                //message d'erreurs
                            break;


                    }
                }

                    
                }
            }

        }
    } 




//tjr plus de lignes






    int nb_cells = 0;
    int array_cells[4] = {MousePoint.x-1,MousePoint.y-1,MousePoint.x+1,MousePoint.y+1}; 

    for (int i=0; i<4;i++) {
        if grid[nb_cells[i]][nb_cells[i]]!= {'a', 'a'}{
            nb_cells ++;
        }
    
    switch (nb_cells){
        case 0:
            //message d'erreurs
        break;
        

    }


    return ; //retourne le nombre de moves possibles
    
}