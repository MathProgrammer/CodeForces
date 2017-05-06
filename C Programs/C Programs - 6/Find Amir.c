#include <stdio.h>

int main()
{
    int no_of_schools, minimum_cost;
    scanf("%d",&no_of_schools);

    /*Firstly, make as many pairs of 0 cost as possible.

    {1 + n}, {2, n-1}, {3, n-2} ... {n/2, n/2 + 1} if n is even. If n is odd, then n/2 + 1 is unpaired.

    These pairs have 0 cost.

    Since a ticket can be used multiple times, it is sufficient to connect these pairs. The minimum way to do this is to pay a cost of 1

    n/2 + (n/2 + 2) = n + 2 = 1 (mod n+1)
    n/2-1 + (n/2 + 3) = n + 2
    n/2-2 + (n/2 + 4) = n + 2

    If n is even, then there are n/2 pairs. These n/2 pairs can be connected in (n/2 - 1) tickets of price 1.
    For example, if there are 10 pairs, there are 5 pairs, and 4 tickets can connect them.
    So, cost is (n/2 - 1).

    If n is odd, then there are n/2 pairs (which can be connected in (n/2 - 1) tickets). Also, n/2 + 1 is isolated. n/2 + 1 should be connected to n/2 + 2.
    So, there are (n/2 - 1 + 1) = n/2 tickets of cost 1.*/

    minimum_cost = (no_of_schools%2 == 0 ? no_of_schools/2 - 1 : no_of_schools/2);
    printf("%d\n", minimum_cost);
    return 0;
}
