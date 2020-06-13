#include <stdio.h>
#include <time.h>

void Save (int playerCount, int gridSize, int grid[playerCount][gridSize][gridSize], int last){

    time_t currentTime;
    struct tm *timeComp;
    
    time(&currentTime);
    timeComp = localtime(&currentTime);

    FILE *file;
    if (last) file = fopen("last", "w"); //inclure le nom du joueur dans la save
    else file = fopen("saves/%d-%02d-%02d_%02d_%02d_%02d", timeComp->tm_year + 1900,
                                                   timeComp->tm_mon + 1,
                                                    timeComp->tm_mday,
                                                    timeComp->tm_hour,
                                                    timeComp->tm_min,
                                                    timeComp->tm_sec);
    fprintf("%d\n%d\n", playerCount, gridSize);
    for (int k = 0; k < playerCount; k ++){
        for (int i = 0; i < gridSize; i ++){
            char tmp[gridSize];
            for (int j = 0; j < gridSize; j ++){
                tmp[j] = grid[k][i][j]+48;
            }
            fpritf(file, "%s\n", tmp);
        }
    }
    fclose(file);
}

void Load(char * path, int * playerCount, int * gridSize, int grid[2][8][8]){
    FILE* file = fopen(path, "r");
    fscanf(file, "%d\n%d\n", playerCount, gridSize);
    for (int k = 0; k < *playerCount; k ++){
        for (int i = 0; i < *gridSize; i++){
            char tmp[*gridSize];
            fscanf(file, "%s\n", tmp);
            for (int j = 0; j < *gridSize; j++){
                grid[k][i][j] = tmp[j] - 48;
            }
        }
    }
    fclose(file);
}