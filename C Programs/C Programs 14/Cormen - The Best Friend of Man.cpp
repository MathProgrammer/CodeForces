#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int no_of_days, minimum_walks_in_two_days;
    scanf("%d %d", &no_of_days, &minimum_walks_in_two_days);

    vector <int> no_of_walks_on_day(no_of_days + 1);
    for(int i = 1; i <= no_of_days; i++)
        scanf("%d", &no_of_walks_on_day[i]);

    int no_of_additional_walks = 0;
    for(int i = 2; i <= no_of_days; i++)
    {
        int walks_in_last_two_days = no_of_walks_on_day[i] + no_of_walks_on_day[i - 1];
        if(walks_in_last_two_days < minimum_walks_in_two_days)
        {
            int no_of_additional_walks_on_day_i = minimum_walks_in_two_days - walks_in_last_two_days;
            no_of_walks_on_day[i] += no_of_additional_walks_on_day_i;

            no_of_additional_walks += no_of_additional_walks_on_day_i;
        }
    }

    printf("%d\n", no_of_additional_walks);
    for(int i = 1; i <= no_of_days; i++)
        printf("%d ", no_of_walks_on_day[i]);

    return 0;
}
