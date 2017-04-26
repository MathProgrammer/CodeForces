#include <stdio.h>
#define min(a, b) (a < b ? a : b)
int main()
{
    int horizontal, vertical;
    scanf("%d %d", &horizontal, &vertical);

    //It doesn't matter which stick is taken. After it is taken, the grid is reduced to (m-1, n-1)
    //Whoever gets the configuration (1, x) or (x, 1) wins.
    //If min(m, n) is even, the minimum becomes odd on Malvika's turn so Malvika gets the configuration (1, x)
    //If min(m, n) is odd, then the minimum is odd on the first player's turns. So, the first player wins.
    printf( min(horizontal, vertical)%2 == 0 ? "Malvika\n" : "Akshat\n");
    return 0;
}
