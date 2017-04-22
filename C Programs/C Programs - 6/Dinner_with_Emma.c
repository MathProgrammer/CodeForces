#include <stdio.h>

#define INFINITY 1e9 + 1
#define min(a, b) (a < b ? a : b)
#define max(a, b) (a > b ? a : b)
int main()
{
    short no_of_streets, no_of_avenues, i, j;
    unsigned int current_cost, minimum_street_cost, maximum_street_minimum_cost = 0;
    scanf("%hu %hu",&no_of_streets, &no_of_avenues);

    for(i = 0; i < no_of_streets; i++)
    {
        //Find the minimum cost on the current street
        minimum_street_cost = INFINITY;
        for(j = 0; j < no_of_avenues; j++)
        {
            scanf("%u",&current_cost);
            minimum_street_cost = min(minimum_street_cost, current_cost);
        }
        //Among the set of minimum costs on each street, choose the maximum element
        maximum_street_minimum_cost = max(maximum_street_minimum_cost, minimum_street_cost);
    }

    printf("%u\n",maximum_street_minimum_cost);
    return 0;
}
