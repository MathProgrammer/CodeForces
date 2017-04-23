#include <stdio.h>
#include <stdlib.h>

#define max(a,b) (a > b ? a : b)

void read(int *, int);
void selection_sort(int *, int);
float find_maximum_radius(int *, int, int);

int main()
{
    int no_of_lanterns, street_length;
    float maximum_radius;
    scanf("%d %d", &no_of_lanterns, &street_length);
    int *lantern_position = malloc(no_of_lanterns*sizeof(int));

    read(lantern_position, no_of_lanterns);
    selection_sort(lantern_position, no_of_lanterns);
    maximum_radius = find_maximum_radius(lantern_position, no_of_lanterns, street_length);

    printf("%.6f",maximum_radius);

    free(lantern_position);
    return 0;
}

float find_maximum_radius(int *lantern_position, int no_of_lanterns, int street_length)
{
    float maximum_radius = 0;
    int i;

    for(i = 1; i < no_of_lanterns; i++)
    {
        maximum_radius = max(maximum_radius, (*(lantern_position + i) - *(lantern_position + i - 1)) );
    }
    //Finding the maximum of distance between first lantern and beginning and last lantern and ending.
    maximum_radius = maximum_radius/2; //We have only compared adjacent lamps so divide by 2.
    maximum_radius = max(maximum_radius, *(lantern_position + 0));
    maximum_radius = max(maximum_radius, street_length - *(lantern_position + no_of_lanterns - 1));
    return maximum_radius;
}

void read(int *lantern_position, int no_of_lanterns)
{
    int i;

    for(i = 0; i < no_of_lanterns; i++)
    {
        scanf("%d",(lantern_position + i));
    }
}

void selection_sort(int *lantern_position, int no_of_lanterns)
{
    int i, j, smallest, smallest_index;

    //Every iteration finds the i-th minima. So, for n elements, we only need to sort n-1 elements. The last element is forced to be in it's correct position.
    for(i = 0; i < no_of_lanterns - 1; i++)
    {
        smallest = *(lantern_position + i);
        smallest_index = i;

        for(j = i + 1; j  < no_of_lanterns; j++)//Go through the list from i to the end to search for a minima
        {
            if(*(lantern_position + j) < smallest)
            {
                smallest = *(lantern_position + j);
                smallest_index = j;
            }
        }

        //Place the i-th minima in the i-th position, and the element at the i-th position where the minima was
        *(lantern_position + smallest_index) = *(lantern_position + i);
        *(lantern_position + i) = smallest;
    }
}
