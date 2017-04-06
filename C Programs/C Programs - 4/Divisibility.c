#include <stdio.h>

int main()
{
    unsigned long long sales, no_of_bonuses;
    scanf("%I64u",&sales);

    //To be divisible by every number from 1-10, it has to be divisible by 2^3, 3^2, 5, 7 i.e. 2520 - Any number divisible by 2520 can be divided by
    //every number from 1-10 because each i in between 1-10, has all it's prime factors in such a number.
    //Any number not divisible by 2520, will have atleast one number such that all it's prime factors aren't in that number. So, the condition is necessary
    //and sufficient
    no_of_bonuses = sales/2520LL;
    printf("%I64u\n",no_of_bonuses);
    return 0;
}
