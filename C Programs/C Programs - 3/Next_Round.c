#include <stdio.h>
#include <stdlib.h>

void read(short *, short);
short find_no_of_winners(short *, short, short );

int main()
{
    short no_of_players, threshold_winner, no_of_winners;

    scanf("%hu %hu",&no_of_players, &threshold_winner);

    short *score = malloc(no_of_players*sizeof(short));

    read(score, no_of_players);
    no_of_winners = find_no_of_winners(score, no_of_players, threshold_winner - 1);//1 is subtracted because we start counting from 0
    printf("%hu\n",no_of_winners);
    free(score);
    return 0;
}

void read(short *score, short no_of_players)
{
    short i;

    for(i = 0; i < no_of_players; i++)
    {
        scanf("%hu",(score + i));
    }
}

short find_no_of_winners(short *score, short no_of_players, short winning_threshold)
{
    short no_of_winners;

    if(*(score + winning_threshold) > 0)
    {
        //If the winning threshold is positive, then check how many players after the winning threshold position, have scored the same number of points
        for(no_of_winners = winning_threshold; no_of_winners < no_of_players; no_of_winners++)
        {
            if(*(score + no_of_winners) != *(score + winning_threshold))
            {
                break;
            }
        }
    }
    else //If the winning threshold is negative, search for the first person ahead of the winning threshold with a positive score
    {
        for(no_of_winners = winning_threshold; no_of_winners >= 0; no_of_winners--)
        {
            if(*(score + no_of_winners) > 0)
            {
                break;
            }
        }
        no_of_winners++;//We have found the first index i, such that Score[i] is positive, increment so that we can count from 1 again.
    }

    return no_of_winners;
}
