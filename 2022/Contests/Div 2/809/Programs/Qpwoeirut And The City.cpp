#include <iostream>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

void solve()
{
    int no_of_elements;
    cin >> no_of_elements;

    vector <int> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];
    }

    const long long oo = 1e18;
    vector <long long> minimum_cost(no_of_elements + 1, oo), maximum_coverage(no_of_elements + 1, 0);
    for(int i = 2; i <= no_of_elements - 1; i++)
    {
        long long amount_here = max(0, max(A[i - 1], A[i + 1]) + 1 - A[i]);

        if(i < 4)
        {
            minimum_cost[i] = amount_here;
            maximum_coverage[i] = 1;
        }
        else if(i >= 4)
        {
            //minimum_cost[i] = amount_here + min(minimum_cost[i - 2], minimum_cost[i - 3]);

            if(maximum_coverage[i - 3] == maximum_coverage[i - 2] && minimum_cost[i - 3] < minimum_cost[i - 2])
            {
                minimum_cost[i] = amount_here + minimum_cost[i - 3];
                maximum_coverage[i] = maximum_coverage[i - 3] + 1;
            }
            else
            {
                minimum_cost[i] = amount_here + minimum_cost[i - 2];
                maximum_coverage[i] = maximum_coverage[i - 2] + 1;
            }
        }

        //cout << "F(" << i << ") = " << minimum_cost[i] << "\n";
    }

    long long answer;

    if(maximum_coverage[no_of_elements - 1] == maximum_coverage[no_of_elements - 2])
    {
        answer = min(minimum_cost[no_of_elements - 1], minimum_cost[no_of_elements - 2]);
    }
    else
    {
        answer = (maximum_coverage[no_of_elements - 1] > maximum_coverage[no_of_elements - 2] ?
                  minimum_cost[no_of_elements - 1] : minimum_cost[no_of_elements - 2]);
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

 
