#include <stdio.h>

int main()
{
    short weight_of_watermelon;

    scanf("%hu",&weight_of_watermelon);

    //An odd number can't be divided into two even numbers because two even numbers always sum up to an even number
    //2 can't be divided into two even numbers smaller than it. (A division of size 0 is not allowed.)
    if( (weight_of_watermelon == 2) || (weight_of_watermelon%2 == 1))
    {
        printf("NO\n");
    }
    else //If Weight = 4n + 2, then the weights are 2n and 2n+2, if weight is 4n, then it is 2n and 2n
    {
        printf("YES\n");
    }
    return 0;
}
