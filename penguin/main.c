#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "board.h"
#include "board_validity.h"
#include "placement.h"
#include "movement.h"

//add unit_test
int main(int argc, const char * argv[]) {

    game mygame;
    int error = 0;
   
    if(argc<2 || (argc>2 && argc!=4 && argc!= 5))
    {
        printf("Invalid Input.\n");
        exit(2);
    }
       
    if(argc==2 && (strcmp(argv[1], "name")==0))
    {
        printf("H");
        exit(0);
    }
    
    if(argc==5) /*placement phase*/
    {
        mygame.max_penguins = atoi(argv[2]+9);//read the number of penguins
        
        read_file(argv[3],&mygame, &error);
        printf("The current board is: \n");
        show_board(&mygame);
        show_playerInfo(&mygame);
        check_available_ice_floe(&mygame, &error);
        place_penguin(&mygame,&error);
        check_initial_score(&mygame, &error);
        if(error==0)
        {
            printf("\nYour penguin is placed.\n");
            show_board(&mygame);
            show_playerInfo(&mygame);
            upload_file(argv[4], &mygame, &error);
        }
        else
            exit(error);
    }
    
    if(argc==4)/*movement phase*/
    {
        read_file(argv[2],&mygame,&error);
        printf("The current board is:\n");
        show_board(&mygame);
        show_playerInfo(&mygame);
        count_max_penguins(&mygame);
        check_players_penguins_num(&mygame, &error);
        if(error==0)
            move_penguin(&mygame, &error);
        if(error==0)
        {
            printf("\nYour penguin is moved.\n");
            show_board(&mygame);
            show_playerInfo(&mygame);
            upload_file(argv[3], &mygame, &error);
        }
        else
            exit(error);
    }

    return 0;
}
//
