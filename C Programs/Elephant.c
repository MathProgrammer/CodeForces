#include <stdio.h>

int main()
{
    unsigned long distance, no_of_steps;

    scanf("%lu", &distance);
    if(distance%5 == 0)
    {
        no_of_steps = distance/5;
    }
    else
    {
        no_of_steps = (distance/5 + 1);
    }
    printf("%lu\n",no_of_steps);
    return 0;
}
