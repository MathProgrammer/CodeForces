#include <stdio.h>

int main()
{
    int no_of_houses, starting_house, no_of_houses_travelled, ending_house;
    scanf("%d %d %d", &no_of_houses, &starting_house, &no_of_houses_travelled);

    /*Simple modular arithmetic -
    (a + b) mod n
    However, the house numbers start from 1. And the modular class start from 0. So,
    {(a - 1 + b) mod n } + 1
    -1 is added to a so that the house starts from 0 and then 1 is added at the end to balance the answer out.

    To ensure the number is positive, if (a - 1 + b)mod n, is negative, then n is added to it to keep it positive.*/
    ending_house = (starting_house - 1 + no_of_houses_travelled)%no_of_houses + 1;
    ending_house = ending_house + (ending_house <= 0 ? no_of_houses : 0);

    printf("%d\n",ending_house);
    return 0;
}
