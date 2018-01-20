#include <cstdio>

int is_lucky(int n)
{
    while(n)
    {
        if(n%10 == 7)
            return true;

        n = n/10;
    }

    return false;
}

int main()
{
    int decrement_time, hour, minute;
    scanf("%d %d %d", &decrement_time, &hour, &minute);

    int no_of_hits = 0;

    while(!is_lucky(hour) && !is_lucky(minute))
    {
        const int NO_OF_MINUTES_IN_HOUR = 60, NO_OF_HOURS_IN_DAY = 24;

        minute -= decrement_time;

        if(minute < 0)
        {
            minute += NO_OF_MINUTES_IN_HOUR;
            hour--;
        }

        if(hour < 0)
        {
            hour += NO_OF_HOURS_IN_DAY;
        }

        no_of_hits++;
    }

    printf("%d\n", no_of_hits);
    return 0;
}
