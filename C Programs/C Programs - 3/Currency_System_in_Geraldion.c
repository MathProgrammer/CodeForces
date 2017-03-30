#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

void read(unsigned int *, unsigned int);
short search_for_1(unsigned int *, unsigned int);

int main()
{
    short is_there_a_1;
    unsigned int no_of_denominations;

    scanf("%u",&no_of_denominations);

    unsigned int *currency_notes = malloc(no_of_denominations*sizeof(unsigned int));

    read(currency_notes, no_of_denominations);
    is_there_a_1 = search_for_1(currency_notes, no_of_denominations);

    if(is_there_a_1)
    {
        printf("-1\n"); //All currencies are reachable
    }
    else
    {
        printf("1"); //There is no 1 so that is the smallest unreachable currency
    }

    free(currency_notes);
    return 0;
}

void read(unsigned int *currency_notes, unsigned int no_of_denominations)
{
    unsigned int i;

    for(i = 0; i < no_of_denominations; i++)
    {
        scanf("%u",(currency_notes + i));
    }
}

short search_for_1(unsigned int *currency_notes, unsigned int no_of_denominations)
{
    short one_found = false;
    unsigned int i;

    for(i = 0; i < no_of_denominations; i++)
    {
        if(*(currency_notes + i) == 1)
        {
            one_found = true;
            break;
        }
    }
    return one_found;
}

