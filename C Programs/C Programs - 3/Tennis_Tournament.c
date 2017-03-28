#include <stdio.h>

int main()
{
    unsigned int no_of_bottles_for_one_player, no_of_participants, no_of_towels_for_one_player;
    unsigned int total_no_of_bottles, total_no_of_towels, no_of_matches;

    scanf("%u %u %u",&no_of_participants, &no_of_bottles_for_one_player, &no_of_towels_for_one_player);

    //If there are n people, then there have to be n-1 matches. Each match eliminates one player and one player only. We need n-1 eliminations to end
    no_of_matches = no_of_participants - 1;
    //Each player takes two bottles and one for the judge
    total_no_of_bottles = no_of_matches*(no_of_bottles_for_one_player)*2 + no_of_matches;//One judge for every match
    total_no_of_towels = no_of_participants*no_of_towels_for_one_player ;

    printf("%u %u\n", total_no_of_bottles, total_no_of_towels);
    return 0;
}
