#include <stdio.h>
#include <stdlib.h>

short find_who_won_more(short *, short *, short);
void read_results(short *, short *, short);
int main()
{
    short no_of_games;
    short winner;
    scanf("%hu",&no_of_games);
    short *mishka_results = malloc(no_of_games*sizeof(short));
    short *chris_results = malloc(no_of_games*sizeof(short));


    read_results(mishka_results, chris_results, no_of_games);
    winner = find_who_won_more(mishka_results, chris_results, no_of_games);//Returns 1 if Mishka is the winner and 2 if Chris wins and 0 for draw

    if(winner == 1)
    {
        printf("Mishka\n");
    }
    else if(winner == 2)
    {
        printf("Chris\n");
    }
    else
    {
        printf("Friendship is magic!^^\n");
    }

    free(mishka_results);
    free(chris_results);
    return 0;
}

void read_results(short *mishka_results, short *chris_results, short no_of_games)
{
    short i;

    for(i = 0; i < no_of_games; i++)
    {
        scanf("%hu %hu",(mishka_results + i), (chris_results + i));
    }
}
short find_who_won_more(short *mishka_results, short *chris_results, short no_of_games)
{
    short i, mishka_win = 0, chris_win = 0;

    for(i = 0; i < no_of_games; i++)
    {
        if(*(mishka_results + i) >  *(chris_results + i))
        {
            mishka_win++;
        }
        else if(*(mishka_results + i) <  *(chris_results + i))
        {
            chris_win++;
        }
    }

    if(mishka_win > chris_win)
    {
        return 1;
    }
    else if(chris_win > mishka_win)
    {
        return 2;
    }
    else //Both are equal
    {
        return 0;
    }
}
