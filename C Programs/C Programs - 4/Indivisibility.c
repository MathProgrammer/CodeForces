#include <stdio.h>

int main()
{
    unsigned long long sales, bonuses, anti_bonuses;
    scanf("%I64u",&sales);

    //Sufficient to check which numbers are not multiples of any of the primes below 10
    //Principle of inclusion and exclusion counts anti-bonus - the number of numbers divisible by one of the primes - 2, 3,,5, 7
    anti_bonuses = (sales/2LL + sales/3LL + sales/5LL + sales/7LL);
    anti_bonuses -= (sales/6LL + sales/10LL + sales/14LL + sales/15LL + sales/21LL + sales/35LL);
    anti_bonuses += (sales/30LL + sales/42LL + sales/70LL + sales/105LL);
    anti_bonuses -= (sales/210LL);
    bonuses = sales - anti_bonuses;

    printf("%I64u\n",bonuses);

    return 0;
}
