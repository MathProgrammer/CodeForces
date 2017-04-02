#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

void read(short *, short);
short check_if_divison_exists(short *, short);
long long find_no_of_divisions(short *, short);

int main()
{
    short no_of_pieces;
    long long no_of_divisions;

    scanf("%hu",&no_of_pieces);

    short *chocolate = malloc(no_of_pieces*sizeof(short));

    read(chocolate, no_of_pieces);
    no_of_divisions = find_no_of_divisions(chocolate, no_of_pieces);

    printf("%I64d\n",no_of_divisions);
    free(chocolate);
    return 0;
}

void read(short *chocolate, short no_of_pieces)
{
    short i;

    for(i = 0; i < no_of_pieces; i++)
    {
        scanf("%hu",(chocolate + i));
    }
}

short check_if_divison_exists(short *chocolate, short no_of_pieces)
{
    short i, division_exists = false;

    for(i = 0; i < no_of_pieces; i++)
    {
        if(*(chocolate + i) == 1)
        {
            division_exists = true;
            break;
        }
    }

    return division_exists;
}
long long find_no_of_divisions(short *chocolate, short no_of_pieces)
{
    short does_division_exist;
    long long no_of_divsions = 1;
    short i, zero_count;

    //Checking if a division exists
    does_division_exist = check_if_divison_exists(chocolate, no_of_pieces);
    if(does_division_exist == false)
    {
        no_of_divsions = 0;
        return no_of_divsions;
    }

    //If there is a run of p 0s in between 2 1s, then a cut can be made in (p + 1) places. We multiply all the (p+1)
    for(i = 0; i < no_of_pieces;)
    {
        if( *(chocolate + i) == 0)
        {
            i++;
            continue;
        }
        else
        {
            //Count the number of zeros in between two consecutive 1s i.e. the current run of 0s.
            for(zero_count = 0; (i + zero_count) < no_of_pieces ; zero_count++)
            {
                if( *(chocolate + i + zero_count + 1) == 1)
                {
                    no_of_divsions = no_of_divsions*(zero_count + 1);
                    break;
                }
            }

            i = i + zero_count + 1; //i resumes from where the run of 0s ends, i.e. the next 1 or the end of the string.
        }
    }
    return no_of_divsions;
}

