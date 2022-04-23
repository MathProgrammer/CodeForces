#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int is_possible(vector <int> &A, int n)
{
    for(int i = 1, current = n; i < A.size(); i++, current++)
    {
        if(abs(A[i] - current) > 1)
        {
            return false;
        }
    }

    return true;
}

void solve()
{
    int no_of_elements;
    cin >> no_of_elements;

    vector <int> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];
    }

    int possible = false;
    for(int beginning = A[1] - 1; beginning <= A[1] + 1; beginning++)
    {
        if(is_possible(A, beginning))
        {
            possible = true;
        }
    }

    cout << (possible ? "Yes" : "No") << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;

    while(no_of_test_cases--)
        solve();

    return 0;
}
