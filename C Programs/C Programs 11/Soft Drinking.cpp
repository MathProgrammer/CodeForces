#include <cstdio>

#define min(a, b) (a < b ? a : b)
#define min_3(a, b, c) min(a, min(b, c))

int main()
{
    int no_of_friends , no_of_bottles, bottle_volume, no_of_limes, no_of_slices, total_salt, one_round_drink, one_round_salt;
    scanf("%d %d %d %d", &no_of_friends, &no_of_bottles, &bottle_volume, &no_of_limes);
    scanf("%d %d %d %d", &no_of_slices, &total_salt, &one_round_drink, &one_round_salt);

    int no_of_toasts = min_3( (no_of_bottles*bottle_volume)/one_round_drink, no_of_limes*no_of_slices, total_salt/one_round_salt )/no_of_friends;
    printf("%d\n", no_of_toasts);

    return 0;
}
