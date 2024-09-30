#ifndef board_validity_h
#define board_validity_h

#include <stdio.h>
#include "board.h"

void check_available_ice_floe(game *mygame, int *error);
//after read file, check if board has enought empty ice floe "10" to hold all penguins

void check_players_penguins_num(game *mygame, int *error);
//in placement phase, after counting max_penguins, check if every player has the same num of penguins
void check_initial_score(game *mygame, int *error);

#endif /* board_validity_h */
