#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void randomPicker(int gridSize, int grid[gridSize][gridSize]){
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
