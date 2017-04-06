#include <stdio.h>

int main()
{
    short winner;
    unsigned long long order_of_square;
    scanf("%I64u",&order_of_square);
    /*If n is an even number, then the square can be divided into four smaller squares. Whatever move, player 1 makes, player 2 makes the same move on the
    diagonally opposite square. In other words, the square rotated by 180 degrees is painted. Player 2 always has a move and wins.
    If n is an odd number, then the first player paints the central square (m+1, m+1), where n = 2m+1,  After that player 1 paints the diagonally opposite
    square that any square that player 2 paints. Player 1 always wins.*/
    if(order_of_square%2 == 1)
    {
        winner = 1;
    }
    else
    {
        winner = 2;
    }
    printf("%hu\n",winner);
    return 0;
}
