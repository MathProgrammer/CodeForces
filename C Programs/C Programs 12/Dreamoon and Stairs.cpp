#include <cstdio>

int main()
{
    int no_of_steps, multiple;
    scanf("%d %d", &no_of_steps, &multiple);

    int minimum_no_of_steps = no_of_steps/2 + no_of_steps%2;

    while(minimum_no_of_steps <= no_of_steps)
    {
        if(minimum_no_of_steps%multiple == 0)
        {
            break;
        }
        minimum_no_of_steps++; //Replace a 2 with two 1s
    }

    printf(minimum_no_of_steps > no_of_steps ? "-1\n" : "%d\n", minimum_no_of_steps);
    return 0;
}
