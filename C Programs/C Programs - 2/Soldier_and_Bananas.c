#include <stdio.h>

int main()
{
    unsigned int no_of_bananas, price_of_one_banana;
    unsigned long money_with_soldier, amount_to_be_borrowed;

    scanf("%u %lu %u", &price_of_one_banana, &money_with_soldier, &no_of_bananas);

    //Sum of bananans = k + 2k + ... wk = w(w+1)/2 * k, where k is the price and w is the number of bananas
    if( (no_of_bananas*(no_of_bananas + 1)/2 )*(price_of_one_banana) < money_with_soldier)
    {
        amount_to_be_borrowed = 0;
    }
    else
    {
        amount_to_be_borrowed = (no_of_bananas*(no_of_bananas + 1)/2 )*(price_of_one_banana) - money_with_soldier;
    }

    printf("%lu\n",amount_to_be_borrowed);
    return 0;
}
