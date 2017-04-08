#include <stdio.h>
#include <stdlib.h>

#define MASK1 0x55555555
#define MASK2 0x33333333
#define MASK3 0x0F0F0F0F
#define MASK4 0x00FF00FF
#define MASK5 0x0000FFFF

void read(int *, int);
int find_maximum_number_of_friends(int *, int,int, int);
int population_count(int);
int main()
{
    short n, maximum_allowed_differences;
    int fedor_army, no_of_soldiers, maximum_no_of_friends;

    scanf("%hu %d %hu", &n, &no_of_soldiers, &maximum_allowed_differences);
    int *army = malloc(no_of_soldiers*sizeof(int));

    read(army, no_of_soldiers);
    scanf("%d",&fedor_army);

    maximum_no_of_friends = find_maximum_number_of_friends(army, no_of_soldiers, maximum_allowed_differences, fedor_army);
    printf("%d\n",maximum_no_of_friends);
    free(army);
    return 0;
}

void read(int *army, int no_of_soldiers)
{
    int i;

    for(i = 0; i < no_of_soldiers; i++)
    {
        scanf("%d",(army + i));
    }
}

int find_maximum_number_of_friends(int *army, int no_of_soldiers,int maximum_allowed_differences, int fedor_army)
{
    int i, no_of_possible_friends = 0;

    for(i = 0; i < no_of_soldiers; i++)
    {   //printf("%d\t%d\tXOR = %d\n",fedor_army, *(army + i), fedor_army^ (*(army + i)) );
        //bitwise XOR on fedor army and every other army. Population count is the number of 1s i.e. the number of differences.
        if( (population_count(fedor_army^ *(army + i))) <= maximum_allowed_differences)
        {
            no_of_possible_friends++;
        }
    }
    return no_of_possible_friends;
}

int population_count(int x)
{
    int no_of_1s = x;

    //x is always 32 bits
    no_of_1s = (no_of_1s &MASK1) + ((no_of_1s >> 1) &MASK1);
    no_of_1s = (no_of_1s &MASK2) + ((no_of_1s >> 2) &MASK2);
    no_of_1s = (no_of_1s &MASK3) + ((no_of_1s >> 4) &MASK3);
    no_of_1s = (no_of_1s &MASK4) + ((no_of_1s >> 8) &MASK4);
    no_of_1s = (no_of_1s &MASK5) + ((no_of_1s >> 16) &MASK5);
    //printf("Population Count = %d\n",no_of_1s);
    return no_of_1s;
}
