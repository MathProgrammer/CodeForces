#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>

#define all(v) (v).begin(), (v).end()

using namespace std;

int main()
{
    int no_of_shops;
    scanf("%d", &no_of_shops);

    vector <int> price_in_shop(no_of_shops);
    for(int i = 0; i < no_of_shops; i++)
        scanf("%d", &price_in_shop[i]);

    sort(all(price_in_shop));

    int no_of_days, budget_day_i;
    scanf("%d", &no_of_days);

    for(int i = 1; i <= no_of_days; i++)
    {
        scanf("%d", &budget_day_i);
        int no_of_eligible_shops = upper_bound(all(price_in_shop), budget_day_i) - price_in_shop.begin();

        printf("%d\n",no_of_eligible_shops); //0 indexed vector so no need to subtract 1.
    }
    return 0;
}
