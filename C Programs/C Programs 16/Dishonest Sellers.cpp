#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define all(v) (v).begin(), (v).end()

struct prices
{
    int now, discount, difference;
};

bool sort_By_Difference(const prices &A, const prices &B)
{
    return (A.difference < B.difference);
}

int main()
{
    int no_of_days, minimum_now_buys;
    scanf("%d %d", &no_of_days, &minimum_now_buys);

    vector <prices> price(no_of_days);
    for(int i = 0; i < no_of_days; i++)
        scanf("%d", &price[i].now);

    for(int i = 0; i < no_of_days; i++)
        scanf("%d", &price[i].discount);

    for(int i = 0; i < no_of_days; i++)
        price[i].difference = price[i].now - price[i].discount;

    sort(all(price), sort_By_Difference);

    int money_used = 0;
    for(int i = 0; i < no_of_days; i++)
    {
        if(i < minimum_now_buys)
            money_used += price[i].now;
        else
            money_used += min(price[i].now, price[i].discount);
    }

    printf("%d\n", money_used);
    return 0;
}
