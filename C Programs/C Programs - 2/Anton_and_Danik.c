#include <stdio.h>
#include <stdlib.h>

short find_who_won_more(char *, unsigned int);

int main()
{
    unsigned int no_of_games;
    short winner;
    scanf("%u",&no_of_games);
    char *results = malloc( (no_of_games + 1)*sizeof(char));

    scanf("%s",results);
    winner = find_who_won_more(results, no_of_games);//Returns 1 if Anton is the winner and 2 if Danik wins and 0 for draw

    if(winner == 1)
    {
        printf("Anton\n");
    }
    else if(winner == 2)
    {
        printf("Danik\n");
    }
    else
    {
        printf("Friendship\n");
    }

    free(results);
    return 0;
}

short find_who_won_more(char *results, unsigned int no_of_games)
{
    unsigned int i, anton_win = 0, danik_win = 0;

    for(i = 0; i < no_of_games; i++)
    {
        if(*(results + i) == 'A')
        {
            anton_win++;
        }
        else if(*(results + i) == 'D')
        {
            danik_win++;
        }
    }

    if(anton_win > danik_win)
    {
        return 1;
    }
    else if(danik_win > anton_win)
    {
        return 2;
    }
    else //Both are equal
    {
        return 0;
    }
}
