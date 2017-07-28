#include <cstdio>

int main()
{
    int no_of_pebble_types, pebble_limit;
    scanf("%d %d", &no_of_pebble_types, &pebble_limit);

    int days_to_collect_all_pebbles = 0;
    for(int i = 1; i <= no_of_pebble_types; i++)
    {
        int pebble_i;
        scanf("%d", &pebble_i);

        days_to_collect_all_pebbles += pebble_i/pebble_limit + (pebble_i%pebble_limit != 0); //Ceil
    }
    days_to_collect_all_pebbles = days_to_collect_all_pebbles/2 + days_to_collect_all_pebbles%2;

    printf("%d\n", days_to_collect_all_pebbles);
    return 0;
}
