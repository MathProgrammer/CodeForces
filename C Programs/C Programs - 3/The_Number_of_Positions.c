#include <stdio.h>

unsigned int minimum(unsigned int, unsigned int);
int main()
{
    short no_of_people, minimum_people_in_front, maximum_people_at_back, no_of_possible_positions;

    scanf("%hu %hu %hu", &no_of_people, &minimum_people_in_front, &maximum_people_at_back);

    //The number of possible positions is the overlap in between (n-a) and (b + 1).
    //one is added because if someone is standing at the (b+1)th position from the back, there are exactly b people behind him and he can stand in any position
    //after this
    no_of_possible_positions = minimum(no_of_people - minimum_people_in_front, maximum_people_at_back + 1);
    printf("%hu\n",no_of_possible_positions);
    return 0;
}

unsigned int minimum(unsigned int a, unsigned int b)
{
    if(a < b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
