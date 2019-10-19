/* Anthony Pionessa
COP3223C
0003
Project 6
10/25/17
*/

//libraries
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

//main function
int main(void){

    //variable declaration
    FILE *ifp = NULL;
    char filename[30];
    int i, j;
    int total_right = 0, right_order = 0;
    int multiple_keys = 0, key_test = 0;
    int lock_num[7], user_key_num[7];

    //cant continue until a valid file name is entered
    while (ifp == NULL) {
        printf("What is the name of the file?\n");
        scanf("%s", filename);
        ifp = fopen(filename, "r");
    }

    //scan the file for the 7 key numbers and their order
    for (i=0; i<7; i++)
        fscanf(ifp, "%d", &lock_num[i]);

    fclose(ifp);

    printf("To get to me treasure you'll have to figure out which of me\n");
    printf("100 keys are used in the 7 locks of me treasure chest.\n");

    //asking for user key numbers then checking the values
    while (!key_test) {

        //reset the checks each loop
        total_right = 0;
        right_order = 0;
        multiple_keys = 0;

        printf("Which keys will ye use?\n");
        //user input of numbers
        for (i=0; i<7; i++)
            scanf("%d", &user_key_num[i]);

        //check for duplicate key numbers
        for (i=0; i<7; i++) {
            for (j=0; j<i; j++) {
                if (user_key_num[i] == user_key_num[j]) {
                    printf("You can only use each key once, matey!\n\n");
                    multiple_keys = 1;
                }
            }
        }

        //check how many keys were correct
        for (i=0; i<7; i++) {
            for (j=0; j<7; j++) {
                if (user_key_num[i] == lock_num[j]) {
                    total_right = total_right + 1;
                }
            }
        }

        //check the order of correct keys if all 7 numbers were correct
        if (total_right == 7) {
            for (i=0; i<7; i++) {
                if (user_key_num[i] == lock_num[i]) {
                    right_order = right_order + 1;
                    if (right_order == 7) {
                        key_test = 1;
                    }
                }
            }
        }

        if (right_order != 7 && multiple_keys != 1)
            printf("%d of those keys are correct! But are they in the right order?\n\n", total_right);
    }

    printf("Arr! You've opened me treasure chest and found...\n");
    printf("A map! To the rest of me treasure on Treasure Island.\n");
    printf("Hahaha!\n");

    return 0;
}
