#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

void solve()
{
    string S;
    cin >> S;

    int all_A = true;
    for(int i = 0; i < S.size(); i++)
    {
        if(S[i] != 'a')
        {
            all_A = false;
            break;
        }
    }

    if(all_A)
    {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    int remaining = 0;
    for(int i = 0, j = S.size() - 1; i < S.size(); i++, j--)
    {
        if(S[j] != 'a')
        {
            remaining = i;
            cout << "a";
            break;
        }
        else
        {
            cout << S[i];
        }
    }

    for(int i = remaining; i < S.size(); i++)
    {
        cout << S[i];
    }
    cout << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;

    while(no_of_test_cases--)
        solve();

    return 0;
}


