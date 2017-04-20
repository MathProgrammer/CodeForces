#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

void read(int *, int);
void reduce_bid(int *, int);
short is_possible(int *, int);

int main()
{
    int no_of_players;
    scanf("%d",&no_of_players);
    int *bid = malloc(no_of_players*sizeof(int));
    read(bid, no_of_players);
    reduce_bid(bid, no_of_players);//dividing the bids till they are coprime to 2 and 3

    printf(is_possible(bid, no_of_players) ? "Yes\n" : "No\n");
    free(bid);
    return 0;
}

//true if all elements are equal
short is_possible(int *bid, int no_of_players)
{
    int i;
    for(i = 1; i < no_of_players; i++)
    {
        if(*(bid + i) != *(bid + 0))
            return false;
    }
    return true;
}
//Every bid is divided till it is coprime to 2 and 3
void reduce_bid(int *bid, int no_of_players)
{
    int i;
    for(i = 0; i < no_of_players; i++)
    {
        while(*(bid + i) %2 == 0)
        {
            *(bid + i) = *(bid + i)/2;
        }
        while(*(bid + i) %3 == 0)
        {
            *(bid + i) = *(bid + i)/3;
        }
    }
}

void read(int *bid, int no_of_players)
{
    int i;
    for(i = 0; i < no_of_players; i++)
    {
        scanf("%d",(bid + i));
    }
}
