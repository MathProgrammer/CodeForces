#include <stdio.h>

int main()
{
    short no_of_problems, vasya, petya, tonya, i, total_problems_solved = 0;
    scanf("%hu",&no_of_problems);
    for(i = 1; i <= no_of_problems; i++)
    {
        scanf("%hu %hu %hu",&vasya, &petya, &tonya);
        total_problems_solved = total_problems_solved + (vasya + petya + tonya >= 2 ? 1 : 0);
    }
    printf("%hu\n",total_problems_solved);
    return 0;
}
