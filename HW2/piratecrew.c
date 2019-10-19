/* Anthony Pionessa
COP3223C
0003
Project 2
9/18/17
*/

//included libraries
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

//main function
int main(void) {

    //variable declaration
    char digging_treasure, able_swim;
    int swim_distance;

    //user input
    printf("Do you like digging for treasure? (Y/N)\n");
    scanf(" %c", &digging_treasure);

    printf("Are you able to swim? (Y/N)\n");
    scanf(" %c", &able_swim);

    if (able_swim == 'Y') {
        printf("How many meters are you able to swim?\n");
        scanf("%d", &swim_distance);

        if (swim_distance >= 100 && digging_treasure == 'Y') {
            printf("You may join the pirate crew! Arrr!");
        }

        else {
            printf("You may not join the crew.");
        }
    }

    else {
        printf("You may not join the crew.");
    }

    return 0;
}
