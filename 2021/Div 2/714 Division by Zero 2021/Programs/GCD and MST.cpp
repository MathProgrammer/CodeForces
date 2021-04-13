#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
    int no_of_elements, p;
    cin >> no_of_elements >> p;

    vector <int> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];
    }

    vector <int> is_connected_right(no_of_elements + 1, false);
    vector < pair <int, int> > values;
    for(int i = 1; i <= no_of_elements; i++)
    {
        values.push_back(make_pair(A[i], i));
    }

    sort(values.begin(), values.end());

    long long weight = 0;
    for(int i = 0; i < values.size(); i++)
    {
        int gcd = values[i].first, index = values[i].second;

        if(gcd >= p)
        {
            break;
        }

        for(int j = index - 1; j >= 1; j--)
        {
            if(A[j] < gcd || A[j]%gcd != 0 || is_connected_right[j])
            {
                break;
            }

            is_connected_right[j] =  true;

            weight += gcd;
        }

        for(int j = index + 1; j <= no_of_elements; j++)
        {
            if(A[j] < gcd || A[j]%gcd != 0 || is_connected_right[j - 1])
            {
                break;
            }

            is_connected_right[j - 1] = true;

            weight += gcd;
        }
    }

    for(int i = 1; i <= no_of_elements - 1; i++)
    {
        if(!is_connected_right[i])
        {
            weight += p;
        }
    }

    cout << weight << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;

    while(no_of_test_cases--)
        solve();

    return 0;
}
