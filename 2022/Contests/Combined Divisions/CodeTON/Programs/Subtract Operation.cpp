#include <iostream>
#include <vector>
#include <map>

using namespace std;

void solve()
{
    int no_of_elements, k;
    cin >> no_of_elements >> k;

    vector <long long> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];
    }

    map <int, int> present;
    for(int i = 1; i <= no_of_elements; i++)
    {
        present[A[i]] = true;
    }

    int possible = false;
    for(int i = 1; i <= no_of_elements; i++)
    {
        if(present[A[i] - k] || present[A[i] + k])
        {
            possible = true;
            break;
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

