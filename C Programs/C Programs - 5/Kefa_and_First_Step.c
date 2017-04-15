#include <stdio.h>
#include <stdlib.h>

void read(unsigned long *, unsigned int);
unsigned int find_length_longest_non_decreasing_streak(unsigned long *, unsigned int);
unsigned long max(unsigned long, unsigned long);

int main()
{
    unsigned int no_of_days, longest_non_decreasing_streak;

    scanf("%u",&no_of_days);

    unsigned long *money_made = malloc(no_of_days*sizeof(unsigned long));
    read(money_made, no_of_days);

    longest_non_decreasing_streak = find_length_longest_non_decreasing_streak(money_made, no_of_days);
    printf("%u\n",longest_non_decreasing_streak);
    free(money_made);
    return 0;
}

unsigned int find_length_longest_non_decreasing_streak(unsigned long *money_made, unsigned int no_of_days)
{
    unsigned int i, longest_non_decreasing_streak = 1, current_non_decreasing_streak = 1 ;

    for(i = 1; i < no_of_days; i++)
    {
        //If A[i] >= A[i-1], current streak increases, else a new streak begins.
        current_non_decreasing_streak = (  ( *(money_made + i) >= *(money_made + i -1) ) ? current_non_decreasing_streak+1 : 1 );

        longest_non_decreasing_streak = max(longest_non_decreasing_streak, current_non_decreasing_streak);
    }

    return longest_non_decreasing_streak;
}

void read(unsigned long *money_made, unsigned int no_of_days)
{
    unsigned int i;

    for(i = 0; i < no_of_days; i++)
    {
        scanf("%lu",(money_made + i));
    }
}

unsigned long max(unsigned long a, unsigned long b)
{
    return ( (a > b) ? a : b);
}
