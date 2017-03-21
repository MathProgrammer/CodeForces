#include <stdio.h>
#include <stdlib.h>

short find_no_of_amazing_performances(unsigned int *,short);
int main()
{
    short no_of_coding_competitions, i, no_of_amazing_performances;
    scanf("%hu",&no_of_coding_competitions);

    unsigned int *coder_score_list = malloc(no_of_coding_competitions*sizeof(unsigned int));
    for(i = 0; i < no_of_coding_competitions; i++)
    {
        scanf("%u",(coder_score_list + i));
    }

    no_of_amazing_performances = find_no_of_amazing_performances(coder_score_list, no_of_coding_competitions);

    printf("%u\n", no_of_amazing_performances);

    free(coder_score_list);
    return 0;
}

//Go through the array linearly and count the number of times there is a new maxima or minima
short find_no_of_amazing_performances(unsigned int *coder_score_list,short no_of_coding_competitions)
{
    unsigned int minimum = *(coder_score_list + 0);
    unsigned int maximum = *(coder_score_list + 0);
    short i, no_time_best_or_worst_record_broken = 0;

    for(i = 0; i < no_of_coding_competitions; i++)
    {
        if( *(coder_score_list + i) < minimum)
        {
            minimum = *(coder_score_list + i);
            no_time_best_or_worst_record_broken++;
        }
        else if( *(coder_score_list + i) > maximum)
        {
            maximum = *(coder_score_list + i);
            no_time_best_or_worst_record_broken++;
        }
    }
    return no_time_best_or_worst_record_broken ;
}
