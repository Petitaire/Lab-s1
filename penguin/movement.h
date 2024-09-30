#ifndef movement_h
#define movement_h

#include <stdio.h>
#include "board.h"

void count_max_penguins(game *mygame);
void move_penguin (game *mygame, int *error);
void check_coordinates(game *mygame, int *error, int row, int col);

#endif /* movement_h */
