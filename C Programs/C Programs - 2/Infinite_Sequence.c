#include <stdio.h>

#define true 1
#define false 0

short check_if_term_falls_in_sequence(long,long,long);

int main()
{
    short does_term_fall_in_sequence;
    long first_term, term_to_be_checked, common_difference;

    scanf("%ld %ld %ld",&first_term, &term_to_be_checked, &common_difference);
    does_term_fall_in_sequence = check_if_term_falls_in_sequence(first_term, term_to_be_checked, common_difference);

    if(does_term_fall_in_sequence)
    {
       printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
    return 0;
}

short check_if_term_falls_in_sequence(long first_term,long term_to_be_checked,long common_difference)
{
    //Prevent division by zero. If difference  = 0, then the sequence consists of one term only, term lies in the sequence iff it is the start term
    if(common_difference == 0)
    {
        if(first_term == term_to_be_checked)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    /*If b falls in the progression, then a + nc = b, where n is a non-negative integer.
    We have to check that (b-a) mod c = 0, and then that (b-a)/c >= 0,
    The second condition is to prevent n from being negative. For example, the series given by (1, 5) should not accept -4. -4 is the '-1'th term.*/
    if( ( (term_to_be_checked - first_term)%common_difference == 0) && ((term_to_be_checked - first_term)/common_difference >= 0) )
    {
        return true;
    }
    else
    {
        return false;
    }
}
