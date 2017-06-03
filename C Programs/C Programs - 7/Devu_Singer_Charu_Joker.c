#include <stdio.h>

int main()
{
    int no_of_songs, total_time_for_songs = 0, minutes_current_song, i, total_time_available, minimum_performance_time, maximum_jokes = -1;
    const int minutes_for_charu_joke = 5;

    scanf("%d %d", &no_of_songs, &total_time_available);
    for(i = 1; i <= no_of_songs; i++)
    {
        scanf("%d", &minutes_current_song);
        total_time_for_songs += minutes_current_song;
    }

    minimum_performance_time = total_time_for_songs + (no_of_songs - 1)*2*minutes_for_charu_joke;

    if(minimum_performance_time <= total_time_available)
    {
        maximum_jokes = (no_of_songs - 1)*2 + (total_time_available - minimum_performance_time)/(minutes_for_charu_joke);
    }

    printf("%d\n",maximum_jokes);
    return 0;
}
