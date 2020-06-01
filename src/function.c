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
        printf("bite fin");
    }
}
int moveRight(int gridSize, int grid[gridSize][gridSize]){
    int cx, nb_evo = 0, z = 1;
    for (int j = 0; j < gridSize; j ++){
        for (int i = gridSize-1; i >= 0; i--){
            z = 1;
            while (1){
<<<<<<< HEAD
                if (i-z>-1){
                    if (grid[i][j] == grid[i-z][j] && grid[i][j]!=0){
=======
                if (z<gridSize-1){
                    if (grid[i][j] == grid[i-z][j]){
                        printf("bite");
>>>>>>> 2a5adfddbf5fe95b2bf7ba98611685b8eea2e4b1
                        grid[i][j] = grid[i][j]*2 ;
                        grid[i-z][j] = 0;
                        nb_evo = 1;
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
                    nb_evo = 1;
<<<<<<< HEAD
                    printf("%d %d %d/", i, cx+1, j);
=======
>>>>>>> 2a5adfddbf5fe95b2bf7ba98611685b8eea2e4b1
                }
                else break;
                cx ++;
                if (cx == gridSize) break;
            }
        }
    }
    return nb_evo;
<<<<<<< HEAD
}

=======

}


>>>>>>> 2a5adfddbf5fe95b2bf7ba98611685b8eea2e4b1
void moveRightbis(int gridSize, int grid[gridSize][gridSize]){
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

int moveLeft(int gridSize, int grid[gridSize][gridSize]){
    int cx, nb_evo = 0, z = 1;
    for (int j = 0; j < gridSize; j ++){
        for (int i = 0; i < gridSize; i++){
            z = 1;
            while (1){
<<<<<<< HEAD
              if (i+z<gridSize){
                  if (grid[i][j] == grid[i+z][j] && grid[i][j]!=0){
=======
              if (z<gridSize-1){
                  if (grid[i][j] == grid[i-z][j]){
                      printf("bite");
>>>>>>> 2a5adfddbf5fe95b2bf7ba98611685b8eea2e4b1
                      grid[i][j] = grid[i][j]*2 ;
                      grid[i+z][j] = 0;
                      nb_evo = 1;
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
<<<<<<< HEAD

  for (int j = 0; j < gridSize; j ++){
      for (int i = 1; i < gridSize; i ++){
=======
  for (int j = 0; j < gridSize; j ++){
      for (int i = 0; i < gridSize; i ++){
>>>>>>> 2a5adfddbf5fe95b2bf7ba98611685b8eea2e4b1
          cx = i;
          while (1){
              if(grid[cx][j] != 0 && grid[cx-1][j] == 0){
                  grid[cx-1][j] = grid[cx][j];
                  grid[cx][j] = 0;
                  nb_evo = 1;
<<<<<<< HEAD
                  printf("%d %d %d/", i, cx-1, j);
              }
              else break;
              cx --;
              if (cx == 0) break;
=======
              }
              else break;
              cx ++;
              if (cx == -1) break;
>>>>>>> 2a5adfddbf5fe95b2bf7ba98611685b8eea2e4b1
          }
      }
    }
    return nb_evo;
  }

<<<<<<< HEAD
int moveDown(int gridSize, int grid[gridSize][gridSize]){
  int cx, nb_evo = 0, z = 1;
  for (int i = 0; i < gridSize; i ++){
      for (int j = gridSize-1; j >= 0; j--){
          z = 1;
          while (1){
              if (j-z>-1){
                  if (grid[i][j] == grid[i][j-z] && grid[i][j]!=0){

                      grid[i][j] = grid[i][j]*2 ;
                      grid[i][j-z] = 0;
                      nb_evo = 1;
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
  for (int i = 0; i < gridSize; i ++){
      for (int j = gridSize-2; j > -1; j --){
          cx = j;

          while (1){
              if(grid[i][cx] != 0 && grid[i][cx+1] == 0){
                  grid[i][cx+1] = grid[i][cx];
                  grid[i][cx] = 0;
                  nb_evo = 1;
                  printf("%d %d %d/", i, cx+1, j);
              }
              else break;
              cx ++;
              if (cx == gridSize) break;
          }
      }
  }

  return nb_evo;

}
=======
>>>>>>> 2a5adfddbf5fe95b2bf7ba98611685b8eea2e4b1

int moveUp(int gridSize, int grid[gridSize][gridSize]){
  int cx, nb_evo = 0, z = 1;
  for (int i = 0; i < gridSize; i ++){
      for (int j = 0; j < gridSize; j++){
          z = 1;
          while (1){
            if (j+z<gridSize){
                if (grid[i][j] == grid[i][j+z] && grid[i][j]!=0){
                    grid[i][j] = grid[i][j]*2 ;
                    grid[i][j+z] = 0;
                    nb_evo = 1;
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

for (int i = 0; i < gridSize; i ++){
    for (int j = 1; j < gridSize; j ++){
        cx = j;
        while (1){
            if(grid[i][cx] != 0 && grid[i][cx-1] == 0){
                grid[i][cx-1] = grid[i][cx];
                grid[i][cx] = 0;
                nb_evo = 1;
                printf("%d %d %d/", i, cx-1, j);
            }
            else break;
            cx --;
            if (cx == 0) break;
        }
    }
<<<<<<< HEAD
  }
  return nb_evo;
=======
>>>>>>> 2a5adfddbf5fe95b2bf7ba98611685b8eea2e4b1
}
