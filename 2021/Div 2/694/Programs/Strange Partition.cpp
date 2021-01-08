#include <iostream>
#include <vector>

using namespace std;

long long ceil(long long n, long long d)
{
    return (n/d) + (n%d != 0);
}

void solve()
{
    int no_of_elements, x;
    cin >> no_of_elements >> x;

    vector <int> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];
    }

    vector <long long> prefix_beauty(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        prefix_beauty[i] = prefix_beauty[i - 1] + ceil(A[i], x);
    }

    long long suffix_sum = A[no_of_elements];
    long long min_beauty = prefix_beauty[no_of_elements], max_beauty = prefix_beauty[no_of_elements];
    for(int i = no_of_elements - 1; i >= 1; i--)
    {
        suffix_sum += A[i];

        min_beauty = min(min_beauty, prefix_beauty[i - 1] + ceil(suffix_sum, x));

        max_beauty = max(max_beauty, prefix_beauty[i - 1] + ceil(suffix_sum, x));
    }

    cout << min_beauty << " " << max_beauty << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;

    while(no_of_test_cases--)
        solve();

    return 0;
}
