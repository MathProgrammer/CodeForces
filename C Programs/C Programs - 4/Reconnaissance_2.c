#include <stdio.h>
#include <stdlib.h>

void get_difference_of_consecutive_soldiers(unsigned int *, unsigned int *,short);
short get_position_of_first_reconnaisance_soldier(unsigned int *,short);
int main()
{
    short no_of_soldiers, i, position_of_first_reconnaissance_soldier, position_of_second_reconnaissance_soldier;
    scanf("%hu",&no_of_soldiers);

    unsigned int *heights_of_soldier =  malloc(no_of_soldiers*sizeof(unsigned int));
    unsigned int *consecutive_height_difference = malloc(no_of_soldiers*sizeof(unsigned int));
    for(i = 0; i < no_of_soldiers; i++)
    {
        scanf("%u",(heights_of_soldier + i));
    }

    get_difference_of_consecutive_soldiers(heights_of_soldier, consecutive_height_difference, no_of_soldiers);
    position_of_first_reconnaissance_soldier = get_position_of_first_reconnaisance_soldier(consecutive_height_difference, no_of_soldiers);

    //IF a soldier is standing at position x, then his neighbour is standing at position (x+1)mod n, where n is the number of people in the circle.
    //The position returned is from 1 to n. We perform mod only on the second number, since we may get (n+1) if the first position is n.
    if(position_of_first_reconnaissance_soldier == no_of_soldiers)
    {
        position_of_second_reconnaissance_soldier = 1;
    }
    else
    {
        position_of_second_reconnaissance_soldier = position_of_first_reconnaissance_soldier + 1;
    }
    printf("%u %u\n",position_of_first_reconnaissance_soldier, position_of_second_reconnaissance_soldier );

    free(heights_of_soldier);
    free(consecutive_height_difference);
    return 0;
}

void get_difference_of_consecutive_soldiers(unsigned int *heights_of_soldier, unsigned int *consecutive_height_difference,short no_of_soldiers)
{
    //C[i] = H[i] - H[(i+1)mod n]
    short i;
    for(i = 0; i < no_of_soldiers; i++)
    {
        *(consecutive_height_difference + i) = abs(*(heights_of_soldier + i) - *(heights_of_soldier + (i + 1)%no_of_soldiers));
    }
}

//Returns position of minimum element of consecutive height difference
short get_position_of_first_reconnaisance_soldier(unsigned int *consecutive_height_difference,short no_of_soldiers)
{
    unsigned int minimum = *(consecutive_height_difference + 0);
    short i, first_soldier_position = 0;

    for(i = 0; i < no_of_soldiers; i++)
    {
        if( *(consecutive_height_difference + i) < minimum)
        {
            minimum = *(consecutive_height_difference + i);
            first_soldier_position = i;
        }
    }
    return first_soldier_position + 1 ;//Pointer arithmetic is performed starting from 0. But, the soldiers are counted starting from 1. So we add 1.
}
