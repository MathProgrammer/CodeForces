#include <iostream>
#include <vector>
#include <cstring>
#include <map>
#include <algorithm>

using namespace std;

int is_even(long long r, long long c)
{
    return ( (r + c)%2 == 0 );
}

void solve()
{
    int no_of_elements;
    cin >> no_of_elements;

    vector < pair <int, int> > P(no_of_elements + 1, make_pair(1, 1));
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> P[i].first;
    }

    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> P[i].second;
    }

    sort(P.begin(), P.end());

    long long distance = 0;
    for(int i = 0; i + 1 <= no_of_elements; i++)
    {
        int source_difference = P[i].first - P[i].second;
        int target_difference = P[i + 1].first - P[i + 1].second;
        int extra_difference = target_difference - source_difference;

        if(extra_difference == 0)
        {
            distance += (is_even(P[i].first, P[i].second) ? P[i + 1].first - P[i].first : 0);

            continue;
        }

        if(is_even(P[i].first, P[i].second))
        {
            distance += ( extra_difference/2 );
        }
        else
        {
            distance += extra_difference/2 + extra_difference%2;
        }
    }

    cout << distance << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;

    while(no_of_test_cases--)
        solve();

    return 0;
}
