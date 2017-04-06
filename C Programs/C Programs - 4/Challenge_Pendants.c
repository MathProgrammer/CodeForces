#include <stdio.h>

int main()
{
    unsigned long long no_of_tables, no_of_ways;
    scanf("%I64u",&no_of_tables);

    //(n + 5 -1) C (5) x (n + 3 - 1) C (3) - The two kinds of pendants' distribution is independent. Stars and bars for both of them.
    //Among any n consecutive integers, one of them is a multiple of n. That is why we divide by 2 after the first two numbers, 3 after first 3, etc.
    //Dividing at each step reduces the chance of overflow that might happen if the entire number is multiplied and then divided.
    no_of_ways = (no_of_tables + 4) * (no_of_tables + 3)/2 * (no_of_tables + 2)/3 * (no_of_tables + 1)/4 * (no_of_tables)/5;
    no_of_ways *= (no_of_tables + 2)*(no_of_tables + 1)/2 *(no_of_tables)/3;
    printf("%I64u\n",no_of_ways);
    return 0;
}
