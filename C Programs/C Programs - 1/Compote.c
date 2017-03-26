#include <stdio.h>

unsigned int min(unsigned int, unsigned int, unsigned int);
int main()
{
    unsigned int lemons,  apples, pears, answer;

    scanf("%u %u %u", &lemons, &apples, &pears);

    /*Lemons, apples and pears have to be in the ratio 1:2:4.
    There will be k lemons, 2k apples and 4k pears.
    k = min(lemons, apples/2, pears/4)
    k is assigned the least of those quantities to ensure we are able to pick k, 2k and 4k from the boxes.
    Otherwise, the class may not have k, 2k or 4k elements to get chosen for the wrong choice of k.
    answer = k + 2k + 4k = 7k */
    answer = 7*min(lemons, apples>>1, pears>>2);
    printf("%u\n" ,answer);
    return 0;
}

unsigned int min(unsigned int a, unsigned int b, unsigned int c)
{
    if(a < b)
    {
        if(a < c)
        {
            return a;
        }
        else
        {
            return c;
        }
    }
    else
    {
        if(b < c)
        {
            return b;
        }
        else
        {
            return c;
        }
    }
}
