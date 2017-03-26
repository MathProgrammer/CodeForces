#include <stdio.h>

short find_no_of_calendar_columns(short, short);
short find_no_of_days_in(short);

int main()
{
    short starting_day, month_no, no_of_days_in_month, answer;

    scanf("%hu %hu", &month_no, &starting_day);

    no_of_days_in_month = find_no_of_days_in(month_no);

    answer = find_no_of_calendar_columns(starting_day, no_of_days_in_month);
    printf("%u\n",answer);
    return 0;
}

short find_no_of_calendar_columns(short starting_day, short no_of_days_in_month)
{
    short answer;

    /*answer = ceil(no_of_days + starting_day - 1). Since, integer division is performed, there will never be any value
    after the decimal point to round off. So, the standard function can't be used and 1 has to be added if it's not a multiple of 7.*/
    if( (no_of_days_in_month + starting_day - 1) % 7 == 0)
    {
        answer = (no_of_days_in_month + starting_day - 1)/7;
    }
    else
    {
        answer = (no_of_days_in_month + starting_day - 1)/7 + 1;
    }
    return answer;
}

short find_no_of_days_in(short month_no)
{
    short no_of_days;
    switch(month_no)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12: no_of_days = 31;
                  break;
        case 4:
        case 6:
        case 9:
        case 11: no_of_days = 30;
                 break;
        case 2 : no_of_days = 28;
    }
    return no_of_days;
}
