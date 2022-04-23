#include <iostream>

using namespace std;

void solve()
{
    string S;
    cin >> S;

    int possible = (S.size() == 1 ? false : true);
    for(int i = 0; i < S.size(); i++)
    {
        if(i == 0)
        {
            if(S[i] != S[i + 1])
            {
                possible = false;
            }
            continue;
        }

        if(i + 1 == S.size())
        {
            if(S[i] != S[i - 1])
            {
                possible = false;
            }

            break;
        }

        if(S[i - 1] != S[i] && S[i] != S[i + 1])
        {
            possible = false;
            break;
        }
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
