#include <iostream>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

int main()
{
    int no_of_elements, max_cost;
    cin >> no_of_elements >> max_cost;

    vector <long long> cost(no_of_elements + 1), damage(no_of_elements + 1), health(no_of_elements + 1);
    vector <long long> max_product(max_cost + 1, 0);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> cost[i] >> damage[i] >> health[i];

        max_product[cost[i]] = max(max_product[cost[i]], damage[i]*health[i]);
    }


    for(int c = 1; c <= max_cost; c++)
    {
        for(int coin_sets = 1; c*1LL*coin_sets <= max_cost; coin_sets++)
        {
            max_product[c*coin_sets] = max(max_product[c*coin_sets], max_product[c]*coin_sets);
        }
    }

    vector <long long> max_product_till(max_cost + 1);
    for(int i = 1; i <= max_cost; i++)
    {
        max_product_till[i] = max(max_product[i], max_product_till[i - 1]);
    }

    int no_of_monsters;
    cin >> no_of_monsters;

    for(int i = 1; i <= no_of_monsters; i++)
    {
        long long damage_here, health_here;
        cin >> damage_here >> health_here;

        long long product = damage_here*health_here;

        int minimum_coins = upper_bound(all(max_product_till), product) - max_product_till.begin();

        cout << (minimum_coins <= max_cost ? minimum_coins : -1) << "\n";
    }

    return 0;
}


