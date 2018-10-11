#include <cstdio>
#include <map>
#include <algorithm>

using namespace std;

void solve(map <int, int> &frequency)
{
    int target;
    scanf("%d", &target);

    int coins_used = 0;

    for(int bit = 30; bit >= 0; bit--)
    {
        if(frequency[1 << bit] == 0) continue;

        int coins_used_here = min(frequency[(1 << bit)], target/(1 << bit));

        target = target - coins_used_here*(1 << bit);

        coins_used += coins_used_here;
    }

    printf("%d\n", target > 0 ? -1 : coins_used);
}

int main()
{
    map <int, int> frequency;
    int no_of_coins, no_of_queries;
    scanf("%d %d", &no_of_coins, &no_of_queries);

    while(no_of_coins--)
    {
        int value;
        scanf("%d", &value);
        frequency[value]++;
    }

    while(no_of_queries--)
        solve(frequency);

    return 0;
}
