#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void randomPicker(int gridSize, int grid[gridSize][gridSize]){
    int available = 0;
    for (int i = 0; i < gridSize; i ++){
        for (int j = 0; j < gridSize; j++){
            if (grid[i][j] == 0){
                available = 1;
                break;
            }
            if(j!=gridSize){
               if (grid[i][j] == grid[i][j+1]){
                   available = 1;
               }
            }
            if(i!=gridSize){
               if (grid[i][j] == grid[i+1][j]){
                   available = 1;
               }
            }
        
        }
        break;
    }
    if (available != 0){
        srand(time(NULL));
        int valid = 0;
        int x, y;
        do{
            x = rand()%gridSize;
            y = rand()%gridSize;
            if (grid[x][y] == 0){
                valid = 1;
                grid[x][y] = 2 + 2*rand()%2;
            }
        } while(!valid);

    }
    else {
        //Message de fin
        printf("bite"); 
    }
}
void moveRightnis(int gridSize, int grid[gridSize][gridSize]){
    int cx;
    int z = 1;
    for (int j = 0; j < gridSize; j ++){
        for (int i = gridSize-1; i > 0; i--){
            z = 1;
            while (1){
                if (z<4){
                    if (grid[i][j] == grid[i-z][j]){
                        printf("bite");   
                        grid[i][j] = grid[i][j]*2 ;
                        grid[i-z][j] = 0;
                        break;
                        }
                    else {
                        z++;
                        }
                    }
                else break;    
            }  
        }
    }
    for (int j = 0; j < gridSize; j ++){
        for (int i = gridSize-2; i > -1; i --){
            cx = i;
            while (1){
                if(grid[cx][j] != 0 && grid[cx+1][j] == 0){
                    grid[cx+1][j] = grid[cx][j];
                    grid[cx][j] = 0;
                }
                else break;
                cx ++;
                if (cx == -1) break;
            }
        }
    }
    
}


void moveRight(int gridSize, int grid[gridSize][gridSize]){
    int oi = gridSize-1, cx;
    for (int j = 0; j < gridSize; j ++){
        for (int i = gridSize-2; i > -1; i--){
            if (grid[i][j] != 0){
                if (grid[i][j] == grid[oi][j]){
                    grid[oi][j] = grid[oi][j]*2;
                    grid[i][j] = 0;
                }
                oi = gridSize-1;
            }
        }
        oi = 0;
    }
    for (int j = 0; j < gridSize; j ++){
        for (int i = gridSize-2; i > -1; i --){
            cx = i;
            while (1){
                if(grid[cx][j] != 0 && grid[cx+1][j] == 0){
                    grid[cx+1][j] = grid[cx][j];
                    grid[cx][j] = 0;
                }
                else break;
                cx ++;
                if (cx == -1) break;
            }
        }
    }
}

void moveLeft(int gridSize, int grid[gridSize][gridSize]){
    int cx;
    for (int j = 0; j < gridSize; j ++){
        for (int i = 1; i < gridSize; i++){
            cx = i;
            while (1){
                if(grid[cx][j] != 0 && grid[cx-1][j] == 0){
                    grid[cx-1][j] = grid[cx][j];
                    grid[cx][j] = 0;
                }
                else break;
                cx --;
                if (cx == -1) {
                    cx ++;
                    break;
                }
            }
            if (grid[cx][j] == grid[cx-1][j] && grid[cx][j] != 0){
                grid[cx][j] = 0;
                grid[cx-1][j]*=2;
            }
        }
    }
}

void moveDown(int gridSize, int grid[gridSize][gridSize]){
    int cy;
    for (int i = 0; i < gridSize; i ++){
        for (int j = gridSize-2; j > -1; j--){
            cy = j;
            while (1){
                if(grid[i][cy] != 0 && grid[i][cy+1] == 0){
                    grid[i][cy+1] = grid[i][cy];
                    grid[i][cy] = 0;
                }
                else break;
                cy ++;
                if (cy == gridSize) {
                    cy --;
                    break;
                }
            }
            if (grid[i][cy] == grid[i][cy+1] && grid[i][cy] != 0){
                grid[i][cy] = 0;
                grid[i][cy+1]*=2;
            }
        }
    }
}

void moveUp(int gridSize, int grid[gridSize][gridSize]){
    int cy;
    for (int i = 0; i < gridSize; i ++){
        for (int j = 1; j < gridSize; j++){
            cy = j;
            while (1){
                if(grid[i][cy] != 0 && grid[i][cy-1] == 0){
                    grid[i][cy-1] = grid[i][cy];
                    grid[i][cy] = 0;
                }
                else break;
                cy --;
                if (cy == -1) {
                    cy ++;
                    break;
                }
            }
            if (grid[i][cy] == grid[i][cy-1] && grid[i][cy] != 0){
                grid[i][cy] = 0;
                grid[i][cy-1]*=2;
            }
        }
    }
}