#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned long long n;
    unsigned long long answer;

    scanf("%I64u",&n);

    if(n < 3)
    {
        printf("%I64u",n);
        return 0;
    }

    if(n%2 == 1)
    {
        answer = (n)*(n-1)*(n-2);
    }
    else if(n%3 != 0)//Even number not a multiple of 3. n and (n-2) are not coprime and n(n-1)(n-3) > (n-1)(n-2)(n-3)
    {
        answer = n*(n-1)*(n-3);
    }
    else //Multiples of 6
    {
        answer = (n-1)*(n-2)*(n-3);
    }

    printf("%I64u\n",answer);
    return 0;
}

