#include <stdio.h>

int main()
{
    int no_of_minima = 0, no_of_maxima = 0, most_beautiful = 0, least_beautiful = 1e9 + 1, no_of_flowers, current_beauty, i;
    long long no_of_choices;
    scanf("%d", &no_of_flowers);

    for(i = 1; i <= no_of_flowers; i++)
    {
        scanf("%d",&current_beauty);

        if(current_beauty == most_beautiful)
            no_of_maxima++;

        if(current_beauty == least_beautiful)
            no_of_minima++;

        if(current_beauty < least_beautiful)
            least_beautiful = current_beauty, no_of_minima = 1;

        if(current_beauty > most_beautiful)
            most_beautiful = current_beauty, no_of_maxima = 1;
    }

    //If all flowers are equally beautiful, then choices = n(n-1)/2
    no_of_choices = ( most_beautiful == least_beautiful ? (no_of_flowers*1LL*(no_of_flowers - 1) )/2 : no_of_minima*1LL*no_of_maxima );

    printf("%d %I64d\n",(most_beautiful - least_beautiful), no_of_choices);
    return 0;
}
