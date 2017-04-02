#include <stdio.h>

short get_last_digit(unsigned long);
int main()
{
    short answer;
    unsigned long power;
    scanf("%lu",&power);

    answer = get_last_digit(power);
    printf("%hu\n",answer);
    return 0;
}

short get_last_digit(unsigned long power)
{
    short i, answer = 1;

    if(power == 0)//n^0 = 1
    {
        return answer;
    }

    /*(10x + a)^{n} = a^n (mod 10) because every other term in (10x + a)^n binomial expansion is a multiple of 10.
    1378^n = 8^n (mod 10). Powers of 8 are cyclic with period 4.*/
    power = power%4;

    if(power == 0)//This means it is a multiple of 4 not equal to zero. We set it to 4 so that we multiply 8 four times (mod 10) instead of 0 times.
    {
        power = 4;
    }

    for(i = 1; i <= power; i++)
    {
        answer = (answer*8)%10;
    }

    return answer;
}
