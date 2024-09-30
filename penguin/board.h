#ifndef board_h
#define board_h

#include <stdio.h>

typedef struct PlayerInfo
{
    char id[10];
    int num;
    int score;
    int penguin_placed;
}Player;

typedef struct GameState
{
    int num_row, num_col;
    int max_penguins;
    char ***board;
    int num_players;
    int our_player_index;
    Player players[9];
}game;

void read_file(const char *filename, game *mygame, int *error);
void show_board(game *mygame);
void show_playerInfo(game *mygame);
void upload_file(const char *filename, game *mygame,int *error);
#endif /* board_h */
