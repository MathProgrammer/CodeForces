#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int no_of_potions, no_of_spells_1, no_of_spells_2;
    cin >> no_of_potions >> no_of_spells_1 >> no_of_spells_2;

    long long time, money;
    cin >> time >> money;

    vector < pair <long long, long long> > reduction(no_of_spells_1 + 1);
    for(int i = 1; i <= no_of_spells_1; i++)
    {
        cin >> reduction[i].second;
    }

    for(int i = 1; i <= no_of_spells_1; i++)
    {
        cin >> reduction[i].first;
    }

    reduction[0].first = 0, reduction[0].second = time;
    sort(reduction.begin(), reduction.end());

    vector < pair <long long, long long> > creation(no_of_spells_2 + 1);
    vector <long long> creation_cost(no_of_spells_2 + 1);
    for(int i = 1; i <= no_of_spells_2; i++)
    {
        cin >> creation[i].second;
    }

    for(int i = 1; i <= no_of_spells_2; i++)
    {
        cin >> creation[i].first;

        creation_cost[i] = creation[i].first;
    }

    sort(creation.begin(), creation.end());
    sort(creation_cost.begin(), creation_cost.end());

    vector <long long> prefix_max(no_of_spells_2 + 1);
    for(int i = 1; i <= no_of_spells_2; i++)
    {
        prefix_max[i] = max(prefix_max[i - 1], creation[i].second);

        //cout << "At i = " << i << " Creation Cost = " << creation[i].first << " Creation = " << creation[i].second << " Best = " << prefix_max[i] << "\n";
    }

    long long best_time = time*no_of_potions;

    for(int i = 0; i <= no_of_spells_1; i++)
    {
        if(reduction[i].first > money)
        {
            break;
        }

        long long remaining_money = max(0LL, money - reduction[i].first);

        int index;
        int left = 0, right = creation_cost.size() - 1;

        if(creation_cost[right] <= remaining_money)
        {
            index = right;
        }
        else
        {
            while(right - left > 1)
            {
                int mid = (left + right)/2;

                if(creation_cost[mid] > remaining_money)
                {
                    right = mid;
                }
                else
                {
                    left = mid;
                }
            }

            index = left;
        }

        long long new_potions = prefix_max[index], new_time = reduction[i].second;

        long long remaining_potions = max(0LL, no_of_potions - new_potions);

        long long time_here = (remaining_potions*new_time);

        best_time = min(best_time, time_here);
    }

    cout << best_time << "\n";

    return 0;
}
