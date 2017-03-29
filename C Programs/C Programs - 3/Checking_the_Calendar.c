#include <stdio.h>
#include <string.h>

#define true 1
#define false 0
#define MAX_DAY_SIZE 10
#define NO_OF_DAYS_IN_WEEK 7

short check_if_consecutive_months_start_with(char[], char[]);
short get_day_no(char[]);
int main()
{
    short is_possible;
    char day_1[MAX_DAY_SIZE], day_2[MAX_DAY_SIZE];

    scanf("%s %s",day_1, day_2);
    is_possible = check_if_consecutive_months_start_with(day_1, day_2);

    if(is_possible)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
    return 0;
}

short check_if_consecutive_months_start_with(char day_1[], char day_2[])
{
    short is_possible = false, no_day_1, no_day_2, difference;
    no_day_1 = get_day_no(day_1);
    no_day_2 = get_day_no(day_2);

    // 7 is added inside to ensure we always get a positive number. (a-b) mod m = (a-b + m) mod m
    difference = (no_day_2 - no_day_1 + NO_OF_DAYS_IN_WEEK)%NO_OF_DAYS_IN_WEEK;

    //Let a month begin on day 1 and have x days. x = 7q + r, r is a number less than 7. The day 7q + 1 will have the same day of the week as the first day
    //The next month begins at day r + 1. The difference in between 1(mod 7) and the allowable values of (r + 1) give us the answer.
    //If the month has 31 days, then 31 = 4(7) + 3. The first day is on 1(mod 7). The next month's first day is on 4(mod 7). So, difference of 3 is allowed
    //IF the month has 30 = 4(7) + 2. A difference of 2 is allowed
    //If the month has 28 = 7(4) days. Both the first days are on 1(mod 7) so a difference of 0 is allowed.
    if( (difference == 3) || (difference == 2) || (difference == 0) )
    {
        is_possible = true;
    }
    return is_possible;
}

short get_day_no(char day[])
{

    if(strcmp (day, "monday") == 0)
    {
        return 1;
    }
    else if(strcmp (day, "tuesday") == 0)
    {
        return 2;
    }
    else if(strcmp (day, "wednesday") == 0)
    {
        return 3;
    }
    else if(strcmp (day, "thursday") == 0)
    {
        return 4;
    }
    else if(strcmp (day, "friday") == 0)
    {
        return 5;
    }
    else if(strcmp (day, "saturday") == 0)
    {
        return 6;
    }
    else if(strcmp (day, "sunday") == 0)
    {
        return 7;
    }

    return -1;
}
