#include <stdio.h>

short find_no_of_chips_at_end(short, unsigned int);

int main()
{
    short no_of_walruses, no_of_chips_left;
    unsigned int no_of_chips;

    scanf("%hu %u",&no_of_walruses, &no_of_chips);
    no_of_chips_left = find_no_of_chips_at_end(no_of_walruses, no_of_chips);

    printf("%hu\n",no_of_chips_left);
    return 0;
}

short find_no_of_chips_at_end(short no_of_walruses, unsigned int no_of_chips)
{
    short i, no_of_chips_left = no_of_chips;

    for(i = 1; no_of_chips_left >= i; i = (i%no_of_walruses)+1) //The number of people goes from 1 to n. The residue class of n goes from 0 - n-1. So, we add 1
    {
        no_of_chips_left = no_of_chips_left - i; //Giving i chips to person i
        //printf("%hu\t%hu\n",i, no_of_chips_left);
    }
    return no_of_chips_left;
}
