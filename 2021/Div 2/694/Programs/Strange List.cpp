#include <iostream>
#include <vector>
#include  <algorithm>

using namespace std;

void solve()
{
    long long no_of_elements, x;
    cin >> no_of_elements >> x;

    vector <int> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];
    }

    int stop = false;
    vector <pair <long long, long long> > value;
    for(int i = 1; i <= no_of_elements; i++)
    {
        value.push_back(make_pair(A[i], 1));
    }

    for(int i = 0; !stop; i++)
    {
        if(value[i].first%x != 0)
        {
            stop = true;
            break;
        }

        value.push_back(make_pair(value[i].first/x, value[i].second*x));
    }

    long long total = 0;
    for(int i = 0; i < value.size(); i++)
    {
        total += value[i].first*value[i].second;
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
