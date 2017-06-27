#include <stdio.h>

int corresponding_decimal(int bitmask)
{
    int decimal = 0;

    //Get the bitmask in decimal For example, 11 should be eleven .. So, we treat it like a polynomial, multiply decimal by 10 at each step and add
    //it to whatever bit was there ... 11 will be 1*10 + 1.
    for(int i = 31; i >= 0; i--)
    {
        decimal = decimal*10 + ( (bitmask & (1 << i) ) != 0) ;
    }
    return decimal;
}

int main()
{
    int limit, no_of_saved_numbers = 0;
    scanf("%d", &limit);

    int max_numbers = (1 << 10) - 1; //At most 2^10 - 1 numbers
    for(int bitmask = 1; bitmask <= max_numbers; bitmask++)
    {
        if(corresponding_decimal(bitmask) > limit)
            break;

        no_of_saved_numbers++;
    }

    printf("%d\n", no_of_saved_numbers);
    return 0;
}
