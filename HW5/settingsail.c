/* 
COP3223C
0003
Project 5
10/13/17
*/

//libraries
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main(void){

    //variable declaration
    FILE *ifp = NULL;
    int coldest_temp, hottest_temp, i, j, current_month[12], days_in_range = 0, best_month;
    float temp_day, percent_in_range[12];
    char weather_file[30];

    printf("Tell me about your crew's preferred temperature for sailing:\n");

    printf("What is the coldest temperature they can sail in?\n");
    scanf("%d", &coldest_temp);

    printf("What is the hottest temperature they can sail in?\n");
    scanf("%d", &hottest_temp);

    //cant continue until a valid file name is entered
    while (ifp == NULL) {
        printf("Please enter the name of the weather data file:\n");
        scanf("%s", weather_file);
        ifp = fopen(weather_file, "r");
    }

    for (i=0; i<12; i++) {
        days_in_range = 0;

        //scans the amount of days recorded in that month
        fscanf(ifp, "%d", &current_month[i]);

        for (j=0; j<current_month[i]; j++) {
                //scans the day for the temperature
                fscanf(ifp, "%f", &temp_day);

                //adds up how many days the temperature was within the ideal range
                if (temp_day >= coldest_temp && temp_day <= hottest_temp)
                    days_in_range = days_in_range + 1;
        }

        //calculates the percent of days in the ideal range
        percent_in_range[i] = ((float) days_in_range / current_month[i]) * 100;

        printf("Month %d: %.1f percent of days in range.\n", i+1, percent_in_range[i]);
    }

    //loops through to find the month that has the highest percent of ideal temperatures
    best_month = 0;
    for (i=1; i<12; i++)
        if (percent_in_range[best_month] < percent_in_range[i])
            best_month = i+1;

    printf("You should leave for the Caribbean in month %d!\n", best_month);

    fclose(ifp);

    return 0;
}
