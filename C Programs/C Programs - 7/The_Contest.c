#include <stdio.h>

#define min(a, b) (a < b ? a : b)
#define max(a, b) (a > b ? a : b)
int main()
{
    int no_of_problems, i, time_i_problem, total_time = 0, no_of_time_periods, minimum_time;
    int start_time[1001], end_time[1001];
    scanf("%d", &no_of_problems);

    for(i = 1; i <= no_of_problems; i++)
    {
        scanf("%d", &time_i_problem);
        total_time += time_i_problem;
    }

    scanf("%d", &no_of_time_periods);
    for(i = 0; i < no_of_time_periods; i++)
        scanf("%d %d", &start_time[i], &end_time[i]);

    for(i = 0; i < no_of_time_periods && total_time > end_time[i]; i++);

    minimum_time = (i == no_of_time_periods ? -1 : max(start_time[i], total_time) );

    printf("%d\n",minimum_time);
    return 0;
}
