#include <stdio.h>

int main()
{
    long long number, answer;
    scanf("%I64d",&number);

    if(number%2 == 0)
    {
        answer = number >> 1; //For even n, the answer is n/2 because f(n) is (1) + (1) + ... +(1)
    }
    else
    {
        answer = (number >> 1) - number;
    }
    printf("%I64d\n",answer);
    return 0;
}
