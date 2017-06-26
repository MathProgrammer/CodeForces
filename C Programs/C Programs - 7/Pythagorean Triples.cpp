#include <stdio.h>

int main()
{
    int side_1;
    long long side_2, side_3, k;
    scanf("%d", &side_1);

    if(side_1 <= 2)
    {
        printf("-1\n");
        return 0;
    }

    /*If n is even, n^2 = 4k, then (2k - 1)^2 + 4k = (2k + 1)^2
    a = root(4k), b = k - 1, c = k + 1

    If n is odd, n^2 = (2k + 1),
    a = root(2k + 1), b = k, c = k + 1*/

    if(side_1%2 == 0)
    {
        k = (side_1*1ll*side_1)/4;

        side_2 = (k - 1);
        side_3 = (k + 1);
    }
    else
    {
        k = ( (side_1*1LL*side_1) - 1)/2;
        side_2 = k;
        side_3 =(k + 1);
    }

    printf("%I64d %I64d\n" ,side_2, side_3);
    return 0;
}
