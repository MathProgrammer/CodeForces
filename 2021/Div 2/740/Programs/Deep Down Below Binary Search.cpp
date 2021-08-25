#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int possible(vector <pair <long long, long long> > &L, long long x)
{
    for(int i = 0; i < L.size(); i++)
    {
        if(x < L[i].first)
        {
            return false;
        }

        x += L[i].second;
    }

    return true;
}

void solve()
{
    int no_of_levels;
    cin >> no_of_levels;

    vector <pair <long long, long long> > level;
    for(int i = 1; i <= no_of_levels; i++)
    {
        int no_of_monsters;
        cin >> no_of_monsters;

        long long power = 0, increment = no_of_monsters;
        for(int j = 1; j <= no_of_monsters; j++)
        {
            long long x;
            cin >> x;

            power = max(power, x + 1 - (j - 1));
        }

        level.push_back(make_pair(power, increment));
    }

    sort(level.begin(), level.end());

    long long left = 0, right = 1e18;
    while(right - left > 1)
    {
        long long mid = (left + right)/2;

        if(possible(level, mid))
        {
            right = mid;
        }
        else
        {
            left = mid;
        }
    }

    cout << right << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;

    while(no_of_test_cases--)
        solve();

    return 0;
}



