/* 
COP3223C
0003
Project 1
8/30/17
 */

//pre-processor directives
//included libraries
#include <stdio.h>

//constants
#define SPAIN_TO_CARIBBEAN 7228
#define CREW_ORANGES .5

//main function
int main(void) {

    //variable declarations
    int ship_travel = 0, crew_members = 0;
    float days_traveled = 0, oranges_needed = 0;

    //user input
    printf("How many kilometers can your ship travel in a day?\n");
    scanf("%d", &ship_travel);

    printf("How many crew members can your ship hold?\n");
    scanf("%d", &crew_members);

    //calculations
    days_traveled = SPAIN_TO_CARIBBEAN / (float) ship_travel;
    oranges_needed = CREW_ORANGES * crew_members * days_traveled;

    //output results
    printf("You will need %.2f oranges to make the trip!\n", oranges_needed);

    return 0;
}
