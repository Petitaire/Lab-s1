#include "placement.h"
#include "board.h"

void place_penguin(game *mygame, int *error)
{
    if(mygame->players[mygame->num_players].penguin_placed==3)
    {
        *error = 1;
        printf("Error. All penguins have been placed.\n");
        return;
    }
    
    int placed =0;
    for(int i=0; i<mygame->num_row && placed==0; ++i)
    {
        for(int j=0; j<mygame->num_col; ++j)
        {
            if(mygame->board[i][j][0] == '1' && mygame->board[i][j][1] == '0')
            {
                int num =mygame->players[mygame->our_player_index].num;
                mygame->board[i][j][0] = '0';
                mygame->board[i][j][1] = '0' + num;
                mygame->players[mygame->our_player_index].score++;
                mygame->players[mygame->our_player_index].penguin_placed++;
                placed=1;
                break;
            }
        }
    }
}
