#include <string.h>
#include "board_validity.h"
#include "board.h"

void check_available_ice_floe(game *mygame, int *error)
{
    int total_penguins = mygame->num_players * mygame->max_penguins;
    int available_ice_floe = 0;
    for(int i=0; i<mygame->num_row; ++i)
    {
        for(int j=0; j<mygame->num_col; ++j)
        {
            if((mygame->board[i][j][0] == '1' && mygame->board[i][j][1] == '0' )||  (mygame->board[i][j][1] != '0')) //check if it's empty ice floe "10" or it's already an occupied ice floe by players "0X"
                available_ice_floe++;
        }
    }
    
    printf("\nActual players: %d, available ice floe: %d\n", mygame->num_players, available_ice_floe);
    
    if(available_ice_floe < total_penguins)
    {
        *error = 2;
        printf("Error. Not enough empty ice floe for all penguins.\n ");
    }
}

void check_players_penguins_num(game *mygame, int *error)
{
    for(int i=0; i<mygame->num_players; ++i)
    {
        int num_penguin = 0;
        for(int m=0; m<mygame->num_row; ++m)
        {
            for(int n=0; n<mygame->num_col; ++n)
            {
                if(mygame->board[m][n][1] == '0' + mygame->players[i].num)
                    num_penguin++;
            }
            
        }
        if(num_penguin != mygame->max_penguins)
        {
            *error=2;
            printf("Error. Player[%d] has different number of penguins.\n", i);
        }
    }
}

void check_initial_score(game *mygame, int *error)
{
    for(int i=0; i<mygame->num_players; ++i)
    {
        if(mygame->players[i].score != 1)
        {
            *error = 2;
            printf("Error. Player[%d]'s initial score is not 1.\n", i);
            break;
        }
    }
}
