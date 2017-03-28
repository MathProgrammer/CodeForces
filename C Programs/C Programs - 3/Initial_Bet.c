#include <stdio.h>

#define NO_OF_PEOPLE 5
int main()
{
    int final_coins[NO_OF_PEOPLE], i, start_coins;
    int total_coins = 0;

    for(i = 0; i < NO_OF_PEOPLE; i++)
    {
        scanf("%d",&final_coins[i]);
    }

    for(i = 0; i < NO_OF_PEOPLE; i++)
    {
        total_coins = total_coins + final_coins[i];
    }

    /*No coins leave the system and no new coins enter the system. The total number of coins remain invariant.
    If in the beginning, everyone had b coins, the total number of coins will always be (NO_OF_PEOPLE*b). If the total number of coins are not a multiple
    of NO_OF_PEOPLE, then there can be no b which can be given to everyone leading to the current conversation.
    Conversely, if the total number of coins is NO_OF_PEOPLE*b, where b is some integer
    we can always trace the steps back to when everyone had b coins in the following way -
    Pick the maximum and minimum number of coins. Donate coins of maximum to minimum till the person with maximum is left with only b coins.
    Now, repeat this procedure for the rest of the people till everyone has b coins. We know this process converges because the total number of coins is
    NO_OF_PEOPLE*b,
    According to the question, 0 is not a legitimate answer so that case must be checked.*/
    if( (total_coins%NO_OF_PEOPLE == 0) && (total_coins != 0) )
    {
        start_coins = total_coins/NO_OF_PEOPLE;
    }
    else
    {
        start_coins = -1;
    }

    printf("%d\n", start_coins);
    return 0;
}
