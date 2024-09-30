//
//  board.c
//  penguin_T5
//
//  Created by qinghe on 02/01/2024.
//

#include "board.h"
#include <string.h>
#include <stdlib.h>

//check if the board is valide(how many fish in total, how many fish do other players have)
//change name write_file
//using macro for game_name
/*first read the current phase, if it's placement phase, read also the max penguins*/

void read_file(const char *filename, game *mygame, int *error)
{
    FILE *file = fopen(filename, "r");
    if(file == NULL)
    {
        *error = 2;
        perror("Input File Error\n");
    }
    
    fscanf(file, "%d %d\n",&mygame->num_row, &mygame->num_col);
    /*read the first line*/
    
    mygame->board=(char***)malloc(mygame->num_row * sizeof(char**));
    for(int i=0; i<mygame->num_row; ++i)
    {
        mygame->board[i]=(char**)malloc(mygame->num_col * sizeof(char*));
        for (int j=0; j<mygame->num_col; ++j)
        {
            mygame->board[i][j]=(char*)malloc(3*sizeof(char));
            /*3: 2 digits + 1 null terminator \0*/
        }
    }
    /*memeory allocation for board*/
    
    for(int i=0; i<mygame->num_row; ++i)
    {
        for(int j=0; j<mygame->num_col; ++j)
        {
            fscanf(file, "%c%c ", &mygame->board[i][j][0], &mygame->board[i][j][1]);
        }
        fscanf(file, "\n");
    }
    /*read board, store each coordinate as two char*/
    
    mygame->num_players=0;
    while(mygame->num_players<9 && fscanf(file, "%s %d %d\n", mygame->players[mygame->num_players].id, &mygame->players[mygame->num_players].num, &mygame->players[mygame->num_players].score)==3)
    {
        mygame->num_players++;
    }
    /*read players info, count num of players*/
    
    fclose(file);
    
    int flag = 0;
    for(int i=0; i<mygame->num_players && flag ==0; ++i)
    {
        if(strcmp(mygame->players[i].id, "teamH")==0)//check if there's team ID
        {
            flag = 1; //team id is found
            mygame->our_player_index = i;
            break;
        }
    }
    
    if(flag == 0 && mygame->num_players < 9) // if there's no team ID
    {
        mygame->our_player_index = mygame->num_players;
        strcpy(mygame->players[mygame->our_player_index].id, "teamH");
        /*num_players is the index of our player*/
        
        mygame->players[mygame->our_player_index].num = mygame->our_player_index+1;
        /*if our player is players[n], the number is n+1*/
        mygame->num_players++;
    }
    /*add information of our team.
    players[0] - players[mygame->num_players-1] represent other players
    players[mygame->num_players] represents the player of our team*/
}

void show_board(game *mygame)
{
    for(int i=0; i<mygame->num_row; ++i)
    {
        for(int j=0; j<mygame->num_col; ++j)
        {
            printf("%c%c ",mygame->board[i][j][0],mygame->board[i][j][1]);
        }
        printf("\n\n");
    }
}/*print board on the screen*/

void show_playerInfo(game *mygame)
{
    for (int i=0; i<mygame->num_players; ++i)
    {
        printf("%s %d %d\n", mygame->players[i].id, mygame->players[i].num, mygame->players[i].score);
        
    }
}/*print user info on the screen*/

void upload_file(const char *filename, game *mygame,int *error)
{
    FILE *file = fopen(filename,"w");
    if(file == NULL)
    {
        *error = 2;
        perror("Input File Error\n");
    }
    
    fprintf(file, "%d %d\n", mygame->num_row, mygame->num_col);
    /*upload first line*/
    
    for(int i=0; i<mygame->num_row; ++i)
    {
        for(int j=0; j<mygame->num_col; ++j)
        {
            fprintf(file, "%c%c ", mygame->board[i][j][0], mygame->board[i][j][1]);
        }
        fprintf(file, "\n");
    }
    /*upload board*/
    
    for(int i=0; i<mygame->num_players; ++i)
    {
        fprintf(file, "%s %d %d\n", mygame->players[i].id, mygame->players[i].num, mygame->players[i].score);
    }
    /*upload players info*/
    
    fclose(file);
    for (int i = 0; i < mygame->num_row; ++i) 
    {
        free(mygame->board[i]);
    }
    free(mygame->board);
}
