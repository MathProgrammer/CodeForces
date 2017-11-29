#include <cstdio>

int get_travel_time(int previous, int current, int no_of_houses)
{
    return (previous <= current ? current - previous : no_of_houses - previous + current);
}

int main()
{
    int no_of_houses, no_of_tasks;
    scanf("%d %d", &no_of_houses, &no_of_tasks);

    int previous_house = 1;
    long long total_time = 0;
    while(no_of_tasks--)
    {
        int current_house;
        scanf("%d", &current_house);

        total_time += get_travel_time(previous_house, current_house, no_of_houses);

        previous_house = current_house;
    }

    printf("%I64d\n", total_time);
    return 0;
}
