#include <stdio.h>

int main()
{
    short no_of_days, i, current_activity, previous_activity = 0, rest_days = 0;
    scanf("%hu",&no_of_days);
    for(i = 1; i <= no_of_days; i++)
    {
        scanf("%hu",&current_activity);

        /*If the gym is closed and there is no contest, he takes rest.
        Else, if gym is open today and he went to the gym the previous day, he is forced to take rest.
        Same reasoning for the contest. If only contest is available today and he went to contest yesterday, he is forced to rest.*/
        if( (current_activity == 0) || (current_activity == 1 && previous_activity == 1) || (current_activity == 2 && previous_activity == 2) )
        {
            rest_days++;
            previous_activity = 0; //Previous activity for the next day.
        }
        else
        {
            //If he went to contest the previous day, go to gym. If he went to gym the previous day go to contest. If it was rest, do either.
            if(current_activity == 3)
            {
                //If previous = 1, do 2 on the current day.
                //If previous = 2, do 1 on the current day
                //If previous = 0, do 3 on the current day
                //If previous = 3, do 3 on the current day as well.
                //What is done on the current day is the previous activity for the next day.
                previous_activity = ( (previous_activity < 3) ? (3 - previous_activity) : previous_activity);
            }
            else //If it isn't 3, then record the exact event.
            {
                previous_activity = current_activity;
            }
        }
    }
    printf("%hu\n",rest_days);
    return 0;
}
