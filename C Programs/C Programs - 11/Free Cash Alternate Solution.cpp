#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int no_of_customers;
    scanf("%d ", &no_of_customers);

    int hour_i, minute_i, previous_hour = 0, previous_minute = 0;
    int no_of_customers_at_this_time = 0, max_customers_arriving_together = 0;

    for(int i = 1; i <= no_of_customers; i++)
    {
        scanf("%d %d", &hour_i, &minute_i);

        no_of_customers_at_this_time = (hour_i == previous_hour && minute_i == previous_minute ? no_of_customers_at_this_time + 1 : 1);

        max_customers_arriving_together = max(max_customers_arriving_together, no_of_customers_at_this_time);

        previous_hour = hour_i;
        previous_minute = minute_i;
    }

    printf("%d\n", max_customers_arriving_together);
    return 0;
}
