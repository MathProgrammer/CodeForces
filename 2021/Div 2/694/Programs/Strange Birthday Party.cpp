#include <iostream>
#include <vector>
#include  <algorithm>

using namespace std;

void solve()
{
    int no_of_elements, no_of_items;
    cin >> no_of_elements >> no_of_items;

    vector <int> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];
    }

    vector <long long> price(no_of_items + 1);
    for(int i = 1; i <= no_of_items; i++)
    {
        cin >> price[i];
    }

    sort(A.begin(), A.end());

    long long total = 0;
    for(int i = 1; i <= no_of_elements; i++)
    {
        total += price[A[i]];
    }

    vector <int> available(no_of_items + 1, true);
    for(int i = no_of_elements, first = 1; i >= 1 && first < A[i]; i--, first++)
    {
        available[first] = false;

        total -= (price[A[i]] - price[first]);
    }

    cout << total << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;

    while(no_of_test_cases--)
        solve();

    return 0;
}
