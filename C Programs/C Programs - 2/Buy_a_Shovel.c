#include <stdio.h>

int main()
{
    unsigned int price_of_a_shovel, total_money_spent;
    short change_available, no_of_shovels;;

    scanf("%u %hu",&price_of_a_shovel, &change_available);

    total_money_spent = price_of_a_shovel;
    for(no_of_shovels = 1; (total_money_spent)%10 != change_available && (total_money_spent % 10 != 0); no_of_shovels++)
    {
        total_money_spent = no_of_shovels*price_of_a_shovel;
        //printf("%u\n",total_money_spent);
    }

    //The number of shovels is incremented one time after the condition is broken. However, if the condition fails the first time, it is not incremented
    if(no_of_shovels != 1)
    {
        no_of_shovels--;
    }
    printf("%hu\n",no_of_shovels);
    return 0;
}
