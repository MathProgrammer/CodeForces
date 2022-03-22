#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int no_of_elements, x, y, max_limit;
    cin >> no_of_elements >> max_limit >> x >> y;

    long long sum = 0;
    vector <long long> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        if(A[i - 1] + x <= max_limit)
        {
            A[i] = A[i - 1] + x;
        }
        else
        {
            A[i] = A[i - 1] - y;
        }

        sum += A[i];
    }

    cout << sum << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;

    while(no_of_test_cases--)
        solve();

    return 0;
}
