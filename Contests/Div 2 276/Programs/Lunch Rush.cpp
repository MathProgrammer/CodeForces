#include <cstdio>

#define max(a, b) (a > b ? a : b)

int main()
{
    int no_of_restaurants, time_limit;
    scanf("%d %d", &no_of_restaurants, &time_limit);

    const int NEGATIVE_INFINITY = -1e9;
    int maximum_joy = NEGATIVE_INFINITY;
    for(int i = 1; i <= no_of_restaurants; i++)
    {
        int time_i, joy_i;
        scanf("%d %d", &joy_i, &time_i);

        if(time_i <= time_limit)
        {
            maximum_joy = max(maximum_joy, joy_i);
        }
        else
        {
            maximum_joy = max(maximum_joy, joy_i - (time_i - time_limit));
        }
    }

    printf("%d\n", maximum_joy);
    return 0;
}
