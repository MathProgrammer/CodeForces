#include <cstdio>
#include <algorithm>
#include <vector>

#define all(v) (v).begin(), (v).end()
using namespace std;

int main()
{
    int no_of_hooks, fine, no_of_guests;
    scanf("%d %d", &no_of_hooks, &fine);

    vector <int> hook_prices(no_of_hooks);
    for(int i = 0; i < no_of_hooks; i++)
        scanf("%d", &hook_prices[i]);


    sort(all(hook_prices));

    scanf("%d", &no_of_guests);

    int unhappy_guests = max(no_of_guests - no_of_hooks, 0);
    int total_fine = unhappy_guests*fine;

    int no_of_satisfied_guests = no_of_guests - unhappy_guests;
    int income = 0;
    for(int i = 0; i < no_of_satisfied_guests; i++)
        income += hook_prices[i];

    printf("%d\n", income - total_fine);

    return 0;
}
