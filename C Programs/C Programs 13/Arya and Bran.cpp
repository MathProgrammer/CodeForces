#include <cstdio>

#define min(a, b) (a < b ? a : b)

int main()
{
    int no_of_days, target_candies;
    scanf("%d %d", &no_of_days, &target_candies);

    const int one_day_limit = 8;
    int total_candies = 0, given_candies = 0, required_days = -1;
    for(int day_i = 1; day_i <= no_of_days; day_i++)
    {
        int box_i, given_on_day_i;
        scanf("%d", &box_i);

        total_candies += box_i;
        given_on_day_i = min(one_day_limit, total_candies);

        total_candies -= given_on_day_i;
        given_candies += given_on_day_i;

        if(given_candies >= target_candies)
        {
            required_days = day_i;
            break;
        }
    }

    printf("%d\n", required_days);
    return 0;
}
