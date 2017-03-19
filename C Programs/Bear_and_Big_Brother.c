#include <stdio.h>

int main()
{
    int limak_weight, bob_weight;
    int year;

    scanf("%d %d",&limak_weight, &bob_weight);

    /*Find the first year in which (limak_weight) > (bob_weight). In other words, the first time the condition, limak <= bob fails
    Counting starts from 0 because we first check the weight of brother at the current moment.*/
    for(year = 0; limak_weight <= bob_weight ; year++)
    {
        limak_weight = 3*limak_weight;
        bob_weight = 2*bob_weight;
    }

    printf("%d\n",year);
    return 0;
}
