#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
    int no_of_elements, extra;
    cin >> no_of_elements >> extra;

    vector <long long> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];
    }

    long long value = 0;
    long long minimum = A[1], maximum = A[1];
    for(int i = 2; i <= no_of_elements; i++)
    {
        minimum = min(minimum, A[i]);
        maximum = max(maximum, A[i]);

        value += abs(A[i] - A[i - 1]);
    }

    if(minimum > 1)
    {
        long long minimum_contribution = min(A[1] - 1, A[no_of_elements] - 1);

        for(int i = 2; i <= no_of_elements; i++)
        {
            minimum_contribution = min(minimum_contribution, (A[i] - 1)*2);
        }

        value += minimum_contribution;
    }

    if(maximum < extra)
    {
        long long maximum_contribution = min(extra - A[1], extra - A[no_of_elements]);

        for(int i = 2; i <= no_of_elements; i++)
        {
            maximum_contribution = min(maximum_contribution, (extra - A[i])*2);
        }

        value += maximum_contribution;
    }

    cout << value << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;

    while(no_of_test_cases--)
        solve();

    return 0;
}

