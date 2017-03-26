#include <stdio.h>
#include <stdlib.h>

void get_room_details(short *, short *, short);
short find_no_of_accomodating_rooms(short *, short *, short);

int main()
{
    short no_of_rooms, no_of_accomodating_rooms;

    scanf("%hu", &no_of_rooms);

    short *no_of_room_occupants = malloc(no_of_rooms*sizeof(short));
    short *capacity_room = malloc(no_of_rooms*sizeof(short));

    get_room_details(no_of_room_occupants,capacity_room,no_of_rooms);
    no_of_accomodating_rooms = find_no_of_accomodating_rooms(no_of_room_occupants,capacity_room,no_of_rooms);

    printf("%hu\n",no_of_accomodating_rooms);

    free(no_of_room_occupants);
    free(capacity_room);
    return 0;
}

void get_room_details(short *no_of_room_occupants, short *capacity_room, short no_of_rooms)
{
    short i;

    for(i = 0; i < no_of_rooms ; i++)
    {
        scanf("%hu %hu",(no_of_room_occupants + i), (capacity_room + i));
    }
}

short find_no_of_accomodating_rooms(short *no_of_room_occupants, short *capacity_room, short no_of_rooms)
{
    short i, no_of_accomodating_rooms = 0;

    for(i = 0; i < no_of_rooms ; i++)
    {
        if( *(capacity_room + i) - *(no_of_room_occupants + i) >= 2) //Accomodate both George and his friend
        {
            no_of_accomodating_rooms++;
        }
    }
    return no_of_accomodating_rooms;
}
