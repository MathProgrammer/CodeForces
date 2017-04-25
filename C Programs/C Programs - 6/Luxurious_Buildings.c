#include <stdio.h>
#include <stdlib.h>

#define maximum(a, b) (a > b ? a : b)

void read(int *, int);
void display(int *, int);
void make_every_building_luxurious(int *, int *, int);

int main()
{
    int no_of_buildings;
    scanf("%d",&no_of_buildings);
    int *no_of_floors = malloc(no_of_buildings*sizeof(int));
    int *no_of_floors_to_be_added = malloc(no_of_buildings*sizeof(int));

    read(no_of_floors, no_of_buildings);
    make_every_building_luxurious(no_of_floors, no_of_floors_to_be_added, no_of_buildings);
    display(no_of_floors_to_be_added, no_of_buildings);

    free(no_of_floors);
    free(no_of_floors_to_be_added);
    return 0;
}

void make_every_building_luxurious(int *no_of_floors, int *no_of_floors_to_be_added, int no_of_buildings)
{
    int i, max = *(no_of_floors + no_of_buildings - 1);
    *(no_of_floors_to_be_added + no_of_buildings - 1) = 0;

    for(i = no_of_buildings - 2; i >= 0; i--)
    {
        *(no_of_floors_to_be_added + i) = (max >= *(no_of_floors + i) ) ? (max - *(no_of_floors + i) + 1) : 0 ;
        max = maximum(max, *(no_of_floors + i) ) ;
    }
}

void read(int *no_of_floors, int no_of_buildings)
{
    int i;
    for(i = 0; i < no_of_buildings; i++)
    {
        scanf("%d",(no_of_floors + i));
    }
}

void display(int *no_of_floors_to_be_added, int no_of_buildings)
{
    int i;
    for(i = 0; i < no_of_buildings; i++)
    {
        printf("%d ",*(no_of_floors_to_be_added + i));
    }
}
