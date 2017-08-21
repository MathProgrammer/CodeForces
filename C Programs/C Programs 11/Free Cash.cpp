#include <cstdio>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    const int NO_OF_MINUTES_IN_HOUR = 60;
    int no_of_customers, no_of_minutes, no_of_hours;
    scanf("%d ", &no_of_customers);

    map <int, int> no_of_customers_arriving_at;
    for(int i = 1; i <= no_of_customers; i++)
    {
        scanf("%d %d", &no_of_hours, &no_of_minutes);

        int arrival_time = no_of_hours*NO_OF_MINUTES_IN_HOUR + no_of_minutes;
        no_of_customers_arriving_at[arrival_time]++;
    }

    int max_customers_arriving_together = 0;
    for(map <int, int> :: iterator it = no_of_customers_arriving_at.begin(); it != no_of_customers_arriving_at.end(); it++)
    {
        max_customers_arriving_together = max(max_customers_arriving_together, it->second);
    }

    printf("%d\n", max_customers_arriving_together);
    return 0;
}
