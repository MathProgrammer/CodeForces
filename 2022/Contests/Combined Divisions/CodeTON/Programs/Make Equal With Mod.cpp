#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
    int no_of_elements;
    cin >> no_of_elements;

    vector <long long> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];
    }

    vector <int> present(3, false);
    for(int i = 1; i <= no_of_elements; i++)
    {
        if(A[i] <= 2)
        {
            present[A[i]] = true;
        }
    }

    int possible = true;
    if(present[1])
    {
        sort(A.begin(), A.end());

        for(int i = 1; i + 1 <= no_of_elements; i++)
        {
            if(A[i] + 1 == A[i + 1])
            {
                possible = false;
                break;
            }
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

 
