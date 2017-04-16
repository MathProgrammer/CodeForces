#include <stdio.h>

int main()
{
    short no_of_test_cases, i;
    long long answer, n, power_of_2_to_be_subtracted = 0;

    scanf("%hu",&no_of_test_cases);

    for(i = 0; i < no_of_test_cases; i++)
    {
        scanf("%I64d",&n);
        power_of_2_to_be_subtracted = 0;
        answer = n*(n+1)/2;

        //The greatest power of 2 less than n is 2^{i-1}, where i is the position of it's most siginificant byte in binary.
        //The sum of all powers of 2 upto 2^i corresponds to a string of i 1s, which is what we construct here.
        while(n > 0)
        {
            power_of_2_to_be_subtracted = (power_of_2_to_be_subtracted << 1) + 1;
            n = n >> 1;
        }

        //Answer = sum(n) - 2(sum (powers of 2) ) because they are also counted once in sum(n).
        answer = answer - (power_of_2_to_be_subtracted << 1);
        printf("%I64d\n",answer);
    }
    return 0;
}
