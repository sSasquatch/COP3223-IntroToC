/* Anthony Pionessa
COP3223C
0003
Project 4
9/28/17
*/

//libraries
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main(void) {

    //variable declaration
    int number_of_days, number_of_trips;
    float time_of_trip, average_trip_time = 0;

    //ask how many days
    printf("How many days will you observe the landing crew?\n");
    scanf("%d", &number_of_days);

    int i;
    for (i=1; i<=number_of_days; i++) {
        //ask how many trips
        printf("How many trips were completed in day #%d?\n", i);
        scanf("%d", &number_of_trips);

        int j;
        for (j=1; j<=number_of_trips; j++) {
            //ask how long the trip was
            printf("How long was trip #%d?\n", j);
            scanf("%f", &time_of_trip);

            //add up all of the trip times
            average_trip_time = average_trip_time + time_of_trip;

            if (j == number_of_trips) {
                //average the trip times
                average_trip_time = average_trip_time / (float) j;

                //print average trip times
                printf("Day #%d: The average time was %.3f.\n", i, average_trip_time);

                //reset the average
                average_trip_time = 0;
            }
        }
    }

    return 0;
}
