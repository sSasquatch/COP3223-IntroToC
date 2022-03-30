/* 
COP3223C
0003
Project 3
9/22/17
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define USED_GEAR 5
#define NEW_GEAR 15

int main(void) {

    int used_bought = 0, new_bought = 0, total_bought;
    int used_cost, new_cost, total_cost = 0;
    int menu_option;
    float average_cost;

    printf("Welcome to the market!\n");

    while (menu_option != 3) {

        printf("What would you like to do?\n 1. Buy New Gear\n 2. Buy Used Gear\n 3. Quit\n");
        scanf("%d", &menu_option);

        if (menu_option != 3) {

            if (menu_option == 1) {
                printf("How many pieces of new gear would you like to buy?\n");
                scanf("%d", &new_bought);
            }

            else if (menu_option == 2) {
                printf("How many pieces of used gear would you like to buy?\n");
                scanf("%d", &used_bought);
            }

            else
                printf("Sorry, %d is not a valid choice.\n", menu_option);
        }
    }

    total_bought = used_bought + new_bought;
    used_cost = used_bought * USED_GEAR;
    new_cost = new_bought * NEW_GEAR;
    total_cost = used_cost + new_cost;
    average_cost = (float) total_cost / (float) total_bought;

    printf("Your total cost is %d gold pieces.\n", total_cost);
    printf("You obtained %d pieces of new gear and %d pieces of used gear.\n", new_bought, used_bought);

    if (total_cost != 0)
        printf("The cost per piece of gear is %.2f pieces of gold.\n", average_cost);

    return 0;
}
