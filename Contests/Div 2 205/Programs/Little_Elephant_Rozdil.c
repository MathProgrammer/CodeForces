#include <stdio.h>
#include <stdlib.h>

void read_time_taken_to_each_city(unsigned int,unsigned long *);
void find_which_city_elephant_goes_to(unsigned int,unsigned long *, unsigned int *,unsigned int *);

int main()
{
    unsigned int no_of_cities, no_of_minima, city_with_minimum_time;
    scanf("%u",&no_of_cities);

    unsigned long *time_taken_to_city = malloc(no_of_cities*(sizeof(unsigned long)));

    read_time_taken_to_each_city(no_of_cities, time_taken_to_city);
    find_which_city_elephant_goes_to(no_of_cities, time_taken_to_city, &city_with_minimum_time, &no_of_minima); //Pass by reference

    if(no_of_minima > 1) //If there is more than one city with the same minimum time, stay in Rozdil
    {
        printf("Still Rozdil\n");
    }
    else //Otherwise, tell the number of the city
    {
        printf("%u\n", city_with_minimum_time);
    }

    free(time_taken_to_city);
    return 0;
}

void read_time_taken_to_each_city(unsigned int no_of_cities,unsigned long *time_taken_to_city)
{
    unsigned int i;

    for(i = 0; i < no_of_cities; i++)
    {
            scanf("%lu",(time_taken_to_city + i));
    }
}

void find_which_city_elephant_goes_to(unsigned int no_of_cities,unsigned long *time_taken_to_city, unsigned int *city_with_minimum_time,unsigned int *no_of_minima)
{
    unsigned int i;

    //First element is marked as minima initially
    *city_with_minimum_time = 0;
    *no_of_minima = 1;

    for(i = 1; i < no_of_cities; i++)
    {
        if( *(time_taken_to_city + i) < *(time_taken_to_city + *(city_with_minimum_time)))//If it is less than minima, change the minima
        {
            *city_with_minimum_time = i;
            *no_of_minima = 1; //Reseting the count of minima
        }
        else if( *(time_taken_to_city + i) == *(time_taken_to_city + *(city_with_minimum_time)))
        {
            *no_of_minima = *no_of_minima + 1;
        }
    }

    if(*no_of_minima == 1)//If there is only one minima, increment the value of city because we have started counting from 0 rather than 1
    {
        *(city_with_minimum_time) = *(city_with_minimum_time) + 1;
    }
}
