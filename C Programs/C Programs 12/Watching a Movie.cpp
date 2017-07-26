#include <cstdio>

int main()
{
    int no_of_interesting_portions, skip_step;
    scanf("%d %d", &no_of_interesting_portions, &skip_step);

    int current_minute = 1, no_of_watched_minutes = 0;
    for(int i = 1; i <= no_of_interesting_portions; i++)
    {
        int beginning_i, end_i;
        scanf("%d %d", &beginning_i, &end_i);

        no_of_watched_minutes += (beginning_i - current_minute)%skip_step + (end_i - (beginning_i - 1));

        current_minute = end_i + 1;
    }

    printf("%d\n", no_of_watched_minutes);
    return 0;
}
