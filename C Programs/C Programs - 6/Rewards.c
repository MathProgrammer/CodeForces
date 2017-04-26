#include <stdio.h>

int main()
{
    int gold_trophy, silver_trophy, bronze_trophy, gold_medal, silver_medal, bronze_medal, total_trophies, total_medals, no_of_shelves;
    int trophy_shelves, medal_shelves;

    scanf("%d %d %d",&gold_trophy, &silver_trophy, &bronze_trophy);
    scanf("%d %d %d",&gold_medal, &silver_medal, &bronze_medal);
    scanf("%d",&no_of_shelves);

    total_trophies = gold_trophy + silver_trophy + bronze_trophy;
    total_medals = gold_medal + silver_medal + bronze_medal;

    trophy_shelves = (total_trophies%5 == 0 ? total_trophies/5 : total_trophies/5 + 1);
    medal_shelves = (total_medals%10 == 0 ? total_medals/10 : total_medals/10 + 1);

    printf(trophy_shelves + medal_shelves <= no_of_shelves ? "YES\n" : "NO\n");
    return 0;
}
