#include <cstdio>

int main()
{
    int no_of_soldiers;
    scanf("%d", &no_of_soldiers);

    const int oo = 100 + 1;
    int tallest_soldier = 0, shortest_soldier = oo;
    int leftmost_tallest = -1, rightmost_shortest = -1;

    for(int i = 1; i <= no_of_soldiers; i++)
    {
        int height_i;
        scanf("%d", &height_i);

        if(height_i > tallest_soldier)
        {
            tallest_soldier = height_i;
            leftmost_tallest = i;
        }

        if(height_i <= shortest_soldier)
        {
            shortest_soldier = height_i;
            rightmost_shortest = i;
        }
    }

    int no_of_swaps = 0;

    if(leftmost_tallest < rightmost_shortest)
        no_of_swaps = (leftmost_tallest - 1) + (no_of_soldiers - rightmost_shortest);
    else
        no_of_swaps = (leftmost_tallest - 1) + (no_of_soldiers - rightmost_shortest) - 1;

    printf("%d\n", no_of_swaps);
    return 0;
}
