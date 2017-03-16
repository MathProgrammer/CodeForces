#include <stdio.h>
#include <stdlib.h>

unsigned int find_maximum_wealth(unsigned int *, short);
unsigned int sum_of_amount_given_to_everyone(unsigned int *, unsigned int, short);

int main()
{
   short no_of_citizens, i;
   unsigned int *wealth_of_citizen, maximum_wealth, amount_distributed;
   scanf("%hu",&no_of_citizens);

   wealth_of_citizen = malloc(no_of_citizens*sizeof(unsigned int));
   for(i = 0; i < no_of_citizens; i++)
    {
            scanf("%u",(wealth_of_citizen + i));
    }

    maximum_wealth = find_maximum_wealth(wealth_of_citizen, no_of_citizens);
    amount_distributed = sum_of_amount_given_to_everyone(wealth_of_citizen,maximum_wealth, no_of_citizens);

    printf("%u\n",amount_distributed);
    free(wealth_of_citizen);
    return 0;
}

unsigned int find_maximum_wealth(unsigned int *wealth_of_citizen, short no_of_citizens)
{
    short i;
    unsigned int max = *(wealth_of_citizen + 0); //First element

    for(i = 1; i < no_of_citizens; i++)
    {
        if(max < *(wealth_of_citizen + i))
        {
            max = *(wealth_of_citizen + i);
        }
    }

    return max;
}

unsigned int sum_of_amount_given_to_everyone(unsigned int *wealth_of_citizen, unsigned int max, short no_of_citizens)
{
    unsigned int money_given_away = 0;
    short i;

    for(i = 0; i < no_of_citizens; i++)
    {
        money_given_away += (max - *(wealth_of_citizen + i));
    }
    return money_given_away;
}
