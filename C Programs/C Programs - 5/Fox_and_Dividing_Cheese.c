#include <stdio.h>
#include <stdlib.h>

int find_common_power(int *, int *, int);
int main()
{
    int piece_1, piece_2;
    int answer;
    scanf("%u %u",&piece_1, &piece_2);

    answer = find_common_power(&piece_1, &piece_2, 2);
    answer = answer + find_common_power(&piece_1, &piece_2, 3);
    answer = answer + find_common_power(&piece_1, &piece_2, 5);

    printf("%d\n", (piece_1 == piece_2 ? answer : -1) );//Checking if the numbers are equal after 2, 3, 5 have been cancelled out completely.
    return 0;
}

//Returns the greatest power of prime which divides both the numbers and reduces both numbers to numbers without the prime.
int find_common_power(int *piece_1, int *piece_2, int prime)
{
    int power_1 = 0, power_2 = 0;
    while(*piece_1 % prime == 0)
    {
        *piece_1 = *piece_1/prime;
        power_1++;
    }
    while(*piece_2 % prime == 0)
    {
        *piece_2 = *piece_2/prime;
        power_2++;
    }

    return abs(power_1 - power_2);
}
