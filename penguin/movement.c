#include "movement.h"
#include "string.h"

void count_max_penguins(game *mygame)
{
    int num =mygame->players[mygame->our_player_index].num;
    mygame->max_penguins = 0;
    
    for(int i=0; i<mygame->num_row; ++i)
    {
        for(int j=0; j<mygame->num_col; ++j)
        {
            if(mygame->board[i][j][1] == '0'+ num)
                mygame->max_penguins++;
        }
    }
    printf("max penguins: %d, team index: %d\n", mygame->max_penguins, num);
}

void move_penguin(game *mygame, int *error)
{
    int num = mygame->players[mygame->our_player_index].num;
    int penguin_checked = 0, moved = 0;
    
    while(penguin_checked < mygame->max_penguins && !moved)
    {
        for(int i=0; i < mygame->num_row; ++i)
        {
            
            for(int j=0; j < mygame->num_col; ++j)
            {
                /*printf("checking [%d][%d], the icefloe is: %s, the last digit is: %c\n", i,j, mygame->board[i][j], mygame->board[i][j][1]);debug*/
                
                if(mygame->board[i][j][1] == '0' + num)
                {
                    printf("the selceted penguin is found at [%d][%d]\n", i, j); /*Debug*/
                    check_coordinates(mygame,error,i,j);
                   
                    moved = (*error == 0);  // simplified conditions for better clarity
                    if(moved==1) /*penguin is moved successfully,exit the loop*/
                        break;
                    else /*error == 1, the selected penguin can't make a move */
                    {
                        penguin_checked += !moved;
                        *error = 1 - moved;
                    }
                }
            }
            
            if(moved==1)
                break;
        }
    }
}

void check_coordinates(game *mygame, int *error, int row, int col)
{
    int dirs[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
    for (int d = 0; d < 4; ++d) { // combined loops and variables for each direction
        int blocked = 0;
        
        // simplified loop for checking each direction
        for (int i = row + dirs[d][0], j = col + dirs[d][1];
             !blocked && i >= 0 && i < mygame->num_row && j >= 0 && j < mygame->num_col;
             i += dirs[d][0], j += dirs[d][1])
            
            if (mygame->board[i][j][1] != '0' || strcmp(mygame->board[i][j], "00") == 0)
                    blocked = 1;
                   
                    else {
                    // improved code for updating board and player scores
                    mygame->board[i][j][1] = '0' + mygame->players[mygame->our_player_index].num;
                    mygame->players[mygame->our_player_index].score += mygame->board[i][j][0] - '0';
                    mygame->board[i][j][0] = '0';
                    mygame->board[row][col][1] = '0';
                    return;
            }
    }
    
    *error = 1;
}



