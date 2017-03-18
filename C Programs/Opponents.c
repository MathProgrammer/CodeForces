#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0
#define MAXIMUM_NO_OF_DAYS 100
#define MAXIIMUM_NO_OF_OPPONENTS 100

void make_list_of_aryan_wins(char[][100],short *, short, short);
short check_if_aryan_wins_on_a_day(char[], short);
void count_no_of_wins_after_last_defeat(short *, short *, short);
short find_maximum_consecutive_wins(short *, short);

int main()
{
    char opponent_schedule[MAXIMUM_NO_OF_DAYS][MAXIIMUM_NO_OF_OPPONENTS];
    short no_of_opponents, no_of_days, maximum_consecutive_wins, i;
    short *aryan_wins = NULL, *consecutive_wins_after_last_defeat = NULL;

    //Reading input
    scanf("%hu  %hu ",&no_of_opponents, &no_of_days);
    aryan_wins = malloc(no_of_days*sizeof(short));
    consecutive_wins_after_last_defeat = malloc(no_of_days*sizeof(short));
    for(i = 0; i < no_of_days; i++)
    {
        scanf("%s",opponent_schedule[i]);
    }

    make_list_of_aryan_wins(opponent_schedule, aryan_wins,no_of_days,no_of_opponents);
    count_no_of_wins_after_last_defeat(consecutive_wins_after_last_defeat,aryan_wins, no_of_days);
    maximum_consecutive_wins = find_maximum_consecutive_wins(consecutive_wins_after_last_defeat,no_of_days);

    printf("%hu\n",maximum_consecutive_wins);

    free(aryan_wins);
    free(consecutive_wins_after_last_defeat);
    return 0;
}

//Aryan wins is a vector such that Win[i] = true if Aryan wins on day i and false otherwise
void make_list_of_aryan_wins(char opponent_schedule[][100],short *aryan_wins, short no_of_days, short no_of_opponents)
{
    short i, does_aryan_win;

    for(i = 0; i < no_of_days; i++)
    {
        does_aryan_win = check_if_aryan_wins_on_a_day(opponent_schedule[i], no_of_opponents);
        if(does_aryan_win == true)
        {
            *(aryan_wins + i) = true;
        }
        else
        {
            *(aryan_wins + i) = false;
        }
    }
}

//Takes the day number, looks at the opponent schedule and predicts if Aryan wins or loses,depending on how many opponents were absent
short check_if_aryan_wins_on_a_day(char one_day_opponent_list[], short no_of_opponents)
{
    short i;

    for(i = 0; i < no_of_opponents; i++)
    {
        if(one_day_opponent_list[i] == '0') //If even one of them is absent, Aryan wins
        {
            return true;
        }
    }

    return false;
}

/*A vector where C[i] = k, if on day i, Aryan has k consecutive wins after his most recent defeat. In other words C[i] is his winning
Streak on day i*/
void count_no_of_wins_after_last_defeat(short *consecutive_wins_after_last_defeat, short *aryan_wins, short no_of_days)
{
    short i;

    *(consecutive_wins_after_last_defeat + 0) = *(aryan_wins + 0);
    for(i = 1; i < no_of_days; i++)
    {
        if( *(aryan_wins + i) == true) //If he wins, add it to his winning streak
        {
            *(consecutive_wins_after_last_defeat + i) = *(consecutive_wins_after_last_defeat + i - 1) + 1;
        }
        else //If he loses, reset his winning streak
        {
            *(consecutive_wins_after_last_defeat + i) = 0;
        }
    }
}

short find_maximum_consecutive_wins(short *consecutive_wins_after_last_defeat, short no_of_days)
{
    short i, maximum_consecutive_wins = *(consecutive_wins_after_last_defeat + 0);

    for(i = 1; i < no_of_days; i++)
    {
        if(*(consecutive_wins_after_last_defeat + i) > maximum_consecutive_wins)
        {
            maximum_consecutive_wins = *(consecutive_wins_after_last_defeat + i);
        }
    }

    return maximum_consecutive_wins;
}
