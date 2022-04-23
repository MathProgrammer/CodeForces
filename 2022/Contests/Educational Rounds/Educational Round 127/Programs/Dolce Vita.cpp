#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
    int no_of_elements, budget;
    cin >> no_of_elements >> budget;

    vector <int> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    vector <long long> prefix_sum(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        prefix_sum[i] = prefix_sum[i - 1] + A[i];
    }

    vector <int> no_of_days_used(no_of_elements + 2, 0);
    for(int i = 1; i <= no_of_elements; i++)
    {
        if(prefix_sum[i] > budget)
        {
            break;
        }

        long long low = 1, high = 1e9 + 1;
        while(high - low > 1)
        {
            long long mid = (low + high)/2;

            if(( prefix_sum[i] + (mid - 1)*i ) > budget)
            {
                high = mid;
            }
            else
            {
                low = mid;
            }
        }

        no_of_days_used[i] = low;

        //cout << "i = " << i << " Days = " << no_of_days_used[i] << "\n";
    }

    long long answer = 0;
    for(int i = 1; i <= no_of_elements; i++)
    {
        answer += (no_of_days_used[i] - no_of_days_used[i + 1])*i;
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

