#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

void solve()
{
    int no_of_elements;
    cin >> no_of_elements;

    vector <int> A(no_of_elements + 1), B(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i] >> B[i];
    }

    vector <pair <int, int> > prices (no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        prices[i].first = A[i];
        prices[i].second = B[i];
    }

    sort(prices.begin() + 1, prices.end());
    reverse(prices.begin() + 1, prices.end());

    vector <int> prefix_max(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        prefix_max[i] = max(prefix_max[i - 1], prices[i].second);
    }

    const int oo = 2e9 + 9;
    int answer = oo;
    set <int> suffix;
    vector <int> suffix_next_greater(no_of_elements + 1, oo), suffix_next_lesser(no_of_elements + 1, oo);
    for(int i = no_of_elements; i >= 1; i--)
    {
        auto it = suffix.lower_bound(prices[i].first);

        if(it != suffix.end())
        {
            suffix_next_greater[i] = *it;
        }

        if(it != suffix.begin())
        {
            it--;
        }
        suffix_next_lesser[i] = *it;

        suffix.insert(prices[i].second);
    }

    for(int i = no_of_elements; i >= 1; i--)
    {
        int answer_here = oo;

        if(i > 1)
        {
            answer_here = abs(prices[i].first - prefix_max[i - 1]);
        }

        if(suffix_next_greater[i] >= prefix_max[i - 1])
        {
            answer_here = min(answer_here, abs(prices[i].first - suffix_next_greater[i]));
        }

        if(suffix_next_lesser[i] >= prefix_max[i - 1])
        {
            answer_here = min(answer_here, abs(prices[i].first - suffix_next_lesser[i]));
        }

        answer = min(answer, answer_here);
    }

    cout << answer << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;

    while(no_of_test_cases--)
        solve();

    return 0;
}

 
