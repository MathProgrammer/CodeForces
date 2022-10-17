#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

void solve()
{
    int no_of_elements;
    cin >> no_of_elements;

    vector <int> A(no_of_elements + 1);
    for(int i = 0; i < no_of_elements; i++)
    {
        cin >> A[i];
    }

    string S;
    cin >> S;

    map <int, char> dictionary;
    int possible = true;
    for(int i = 0; i < S.size(); i++)
    {
        if(dictionary[A[i]] != 0)
        {
            if(dictionary[A[i]] != S[i])
            {
                possible = false;
                break;
            }
        }

        dictionary[A[i]] = S[i];
    }

    cout << (possible ? "YES" : "NO") << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;

    while(no_of_test_cases--)
        solve();

    return 0;
}
