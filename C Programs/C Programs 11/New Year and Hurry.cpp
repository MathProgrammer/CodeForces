#include <cstdio>

int main()
{
    int travel_time, no_of_problems;
    scanf("%d %d", &no_of_problems, &travel_time);

    const int NO_OF_MINUTES_IN_HOUR = 60;
    int time = 4*NO_OF_MINUTES_IN_HOUR;

    time = time - travel_time;

    int solved_problems = 0;

    for(int problem_i = 1; problem_i <= no_of_problems; problem_i++)
    {
        if(time - 5*problem_i >= 0)
        {
            time = time - 5*problem_i;
            solved_problems++;
        }
        else //Time is insufficient
        {
            break;
        }
    }

    printf("%d\n", solved_problems);
    return 0;
}
