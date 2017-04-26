#include <stdio.h>

#define min(a, b) (a < b ? a : b)
int main()
{
    int side_a, side_b, radius;
    scanf("%d %d %d",&side_a, &side_b, &radius);

    //If the first player can't place a plate, the second player wins. Else, the first player always wins. He places a plate in the center of the table.
    //And then places a table diagonally opposite to wherever the second player places a table
    printf(min(side_a, side_b) < (2*radius) ? "Second\n" : "First\n");
    return 0;
}
