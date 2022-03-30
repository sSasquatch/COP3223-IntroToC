/* 
COP3223C
0003
Project 8
11/29/17
*/

#include <stdio.h>

struct pirate {
    int dig;
    int carry;
};

struct map {
    int sand;
    int treasure;
};

void ongoingGame(struct map map[3][3], struct pirate pirates[1][4], int *treasure_taken);
void checkEnding(struct map map[3][3], int *hours, int treasure_taken);

int main(void) {
    FILE *ifp = NULL;
    char filename[30];
    int i, j;
    int hours = 8, treasure_taken = 0;

    struct map map[3][3];
    struct pirate pirates[1][4];

    printf("You have arrived at Treasure Island!\n");

    //user file input
    while (ifp == NULL) {
        printf("What is the name of your map?\n");
        scanf("%s", filename);
        ifp = fopen(filename, "r");
    }

    //initialize the map
    for(i=0; i<3; i++)
        for(j=0; j<3; j++) {
            fscanf(ifp, "%d", &map[i][j].sand);
            fscanf(ifp, "%d", &map[i][j].treasure);
        }

    //initialize the pirate crew
    for(i=0; i<1; i++)
        for(j=0; j<4; j++) {
            fscanf(ifp, "%d", &pirates[i][j].dig);
            fscanf(ifp, "%d", &pirates[i][j].carry);
        }

    fclose(ifp);
    printf("\n");

    //first check is for if the treasure is all taken before a round is finished
    while(hours > 0){
        printf("You have %d hours left to dig up the treasure.\n", hours);
        ongoingGame(map, pirates, &treasure_taken);
        checkEnding(map, &hours, treasure_taken);
        if(hours == 0)
            break;
        hours = hours - 1;
        checkEnding(map, &hours, treasure_taken);
    }

    return 0;
}

//pre-condition: treasure_taken is a positive integer and map/pirates
//              is initialized in main with positive integers from an input file
//post-condition: prints out the map and checks what is left in each map space
void ongoingGame(struct map map[3][3], struct pirate pirates[1][4], int *treasure_taken) {
    int i, j;
    int map_row, map_col;
    int crew_mem = 0, treasure_check = 0;

    printf("Crew\t Dig\t Carry\t\n");

    //print pirate number and stats
    for(i=0; i<4; i++)
        printf("%d\t %d\t %d\t\n", i + 1, pirates[0][i].dig, pirates[0][i].carry);

    printf("\n");

    while(crew_mem < 4) {
        printf("Where would you like to send crew member %d?\n", crew_mem + 1);
        //print grid
        for(i=0; i<3; i++) {
            for(j=0; j<3; j++) {
                if(map[i][j].sand > 0)
                    printf("%ds\t ", map[i][j].sand);
                else if(map[i][j].treasure > 0 && map[i][j].sand <= 0)
                    printf("%dT\t ", map[i][j].treasure);
                else
                    printf("--\t ");
            }
            printf("\n");
        }
        printf("\n");
        scanf("%d %d", &map_row, &map_col);

        //check sand/treasure taken
        if(map[map_row - 1][map_col - 1].sand > 0) {
            map[map_row - 1][map_col - 1].sand = map[map_row - 1][map_col - 1].sand - pirates[0][crew_mem].dig;
            if(map[map_row - 1][map_col - 1].sand <= 0)
                printf("You have removed all of the sand from this section!\n\n");
            else
                printf("You have removed some of the sand from this section.\n\n");
        }
        else if(map[map_row - 1][map_col - 1].treasure > 0) {
            *treasure_taken = treasure_taken + map[map_row - 1][map_col - 1].treasure;
            map[map_row - 1][map_col - 1].treasure = map[map_row - 1][map_col - 1].treasure - pirates[0][crew_mem].carry;
            if(map[map_row - 1][map_col - 1].treasure <= 0)
                printf("You take all of the treasure back to the ship!\n\n");
            else
                printf("You take some of the treasure back to the ship.\n\n");
        }
        else
            printf("This section has already been cleared.\n\n");

        //check to see if all of the treasure has been taken
        i = 0;
        while(i < 3) {
            for(i=0; i<3; i++)
                for(j=0; j<3; j++)
                    if(map[i][j].treasure <= 0)
                        treasure_check = treasure_check + 1;
            if(treasure_check == 9)
                return;
        }

        //update crew member
        crew_mem = crew_mem + 1;
    }
    printf("\n");

    return;
}

//pre-condition: map is initialized in main with positive integers from an
//              input file and hours/treasure_taken are positive integers
//post-condition: returns if the game is over and nothing if the game is not
void checkEnding(struct map map[3][3], int *hours, int treasure_taken) {
    int i, j;
    int treasure_check = 0;

    //check if all of the treasure is taken
    if(hours > 0) {
        for(i=0; i<3; i++)
            for(j=0; j<3; j++)
                if(map[i][j].treasure <= 0)
                    treasure_check = treasure_check + 1;
        if(treasure_check == 9) {
            printf("All of the pirate's treasure belongs to you now!\n");
            *hours = 0;
            return;
        }
    }
    //check if the hours are used up
    else if(hours == 0) {
        printf("You are forced to evacuate the island. You have claimed %d pieces of the pirate's treasure!\n", treasure_taken);
        return;
    }
    else
        return;
}
