#include <stdio.h>
unsigned long long power(unsigned long long, unsigned long long);
int main()
{
    unsigned long long no_of_parking_positions, no_of_arrangements, four_power_n_minus_3;
    scanf("%I64u",&no_of_parking_positions);

    four_power_n_minus_3 = power(4, no_of_parking_positions - 3);

    no_of_arrangements = 6*(four_power_n_minus_3 * 4) + (no_of_parking_positions - 3)*9*(four_power_n_minus_3);
    printf("%I64u",no_of_arrangements);
    return 0;
}

unsigned long long power(unsigned long long base, unsigned long long exponent)
{
    unsigned long long answer = 1;

    if(exponent == 0)
    {
        return answer;
    }

    //Binary exponentiation algorithm. Number is squared as many times as the number of 0s in binary representation. x^5 = (x^2)^2*x
    while(exponent > 0)
    {
        if(exponent%2 == 1)
        {
            answer = answer*base;
        }
        base = base*base;
        exponent = exponent >> 1;
    }
    return answer;
}
