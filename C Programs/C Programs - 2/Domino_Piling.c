#include <stdio.h>

int main()
{
    short no_of_rows, no_of_columns;
    short no_of_dominos;

    scanf("%hu %hu", &no_of_rows, &no_of_columns);

    /*If there are m*n squares, and m*n is an even number, all the squares can be tiled. 2 squares for a domino, so m*n/2
    If m*n is an odd number, then m*n-1 squares can be tiled. So, (m*n-1)/2. But, since m*n is an odd number - floor(m*n/2)
    In other words, simple integer division by 2.*/
    no_of_dominos = (no_of_rows*no_of_columns) >> 1;

    printf("%hu\n",no_of_dominos);
    return 0;
}
