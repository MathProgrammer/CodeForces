#include <stdio.h>
#include<stdlib.h>
#include <string.h>

int main()
{
    short no_of_observed_days, *size_of_moon, i;
    char answer[4];

    scanf("%hu",&no_of_observed_days);

    //Allocating memory for and recording the observations
    size_of_moon = malloc(no_of_observed_days*sizeof(short));
    for(i = 0; i < no_of_observed_days; i++)
    {
        scanf("%hu", (size_of_moon + i));
    }

    if(*(size_of_moon + no_of_observed_days - 1) == 15) //Last observation is 15. Can only go down
    {
        strcpy(answer,  "DOWN");
    }
    else if(*(size_of_moon + no_of_observed_days - 1) == 0)//Last observation is 0. Can only go up
    {
        strcpy(answer,  "UP");
    }

    else if(no_of_observed_days == 1) //Unless the last observation is 0 or 15, 1 observation is insufficient
    {
            strcpy(answer,  "-1");
    }

    else
    {
        if(*(size_of_moon + no_of_observed_days - 1) > *(size_of_moon + no_of_observed_days - 2))//If a_n > a_{n-1}, moon goes up since a_n != 15
        {
            strcpy(answer,  "UP");
        }
        else //a_n < a_{n-1}, moon goes down since a_n != 0
        {
           strcpy(answer,  "DOWN");
        }
    }

    free(size_of_moon);

    printf("%s\n",answer);
    return 0;
}
