#include <cstdio>

#define MAX_TIME_LENGTH 5 + 1

int main()
{
    int savings = 0, date;
    char of[2 + 1], time_period[MAX_TIME_LENGTH];
    scanf("%d %s %s", &date ,of, time_period); //Scanf reads a string till it encounters a whitespace ... so I used two strings.

    if(time_period[0] == 'm') //Month
    {
        savings = 12*(date <= 29) + 11*(date == 30) + 7*(date == 31); //Only one of these can be true.
    }
    else if(time_period[0] == 'w') //Week
    {
        savings = 52 + (date == 5 || date == 6); // Days 6 and 7 occur one more time
    }

    printf("%d\n", savings);
    return 0;
}
